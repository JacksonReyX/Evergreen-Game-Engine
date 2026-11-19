#include <fstream>
#include <sstream>
#include <iostream>

#include "LevelLoader.h"
#include "game.h"

#include "../Components/TransformComponent.h"
#include "../Components/RigidBodyComponent.h"
#include "../Components/BoxColliderComponent.h"
#include "../Components/AnimationComponent.h"
#include "../Components/ShapeComponent.h"
#include "../Components/SpriteComponent.h"
#include "../Components/CameraFollowComponent.h"
#include "../Components/KeyboardControlledComponent.h"
#include "../Components/ProjectileEmitterComponent.h"
#include "../Components/HealthComponent.h"
#include "../Components/TextLabelComponent.h"
#include "Components/MoveableComponent.h"

#include <sol.hpp>




void LevelLoader::load(sol::state& lua, std::unique_ptr<Registry>& registry, std::unique_ptr<AssetStore>& asset_store, Game& game, const std::string& config_file)
{

    //error handling for if file is not a lua script
	sol::load_result script = lua.load_file(config_file);
	if (!script.valid()) {
		sol::error err = script;
		std::string errorMessage = err.what();
		Logger::Err("Error loading the lua script: " + errorMessage);
		return;
	}

    //asset_store->addFont("charriot-font", "./assets/fonts/charriot.ttf");
    //asset_store->addFont("pico8-font-5", "./assets/fonts/pico8.ttf");

	// Executes the script using the Sol state
	lua.script_file("./" + config_file);

	// Read the big table for the current level
	sol::table level = lua["Level"];

	/////////////////////////////////////////////////////////////////
	// Window
	/////////////////////////////////////////////////////////////////

		sol::optional<sol::table> window_opt = level["window"];

		if (window_opt != sol::nullopt)
		{
			sol::table window = window_opt.value();

			game.window_width_ =
				window["width"].get_or(game.window_width_);

			game.window_height_ =
				window["height"].get_or(game.window_height_);
		}


	////////////////////////////////////////////////////////////////////////////
	// Read the level assets
	////////////////////////////////////////////////////////////////////////////
	sol::table assets = level["assets"];

	int i = 0;
	while (true) {
		sol::optional<sol::table> hasAsset = assets[i];
		if (hasAsset == sol::nullopt) {
			break;
		}
		sol::table asset = assets[i];
		std::string assetType = asset["type"];
		std::string assetId = asset["id"];
		if (assetType == "texture") {
			asset_store->addTexture(assetId, asset["file"]);
			Logger::Log("A new texture asset was added to the asset store, id: " + assetId);
		}
		if (assetType == "font") {
			asset_store->addFont(assetId, asset["file"]);
			Logger::Log("A new font asset was added to the asset store, id: " + assetId);
		}
		i++;
	}

	////////////////////////////////////////////////////////////////////////////
	// Read the level tilemap information
	////////////////////////////////////////////////////////////////////////////
	sol::table map = level["tilemap"];
	std::string mapFilePath = map["map_file"];
	std::string mapTextureAssetId = map["texture_asset_id"];
    std::string colliderMapPath = map["collider_map_file"];
	int map_num_rows = map["num_rows"];
	int map_num_cols = map["num_cols"];
	int tile_size = map["tile_size"];
	double tile_scale = map["scale"];
	std::fstream mapFile;
	mapFile.open(mapFilePath);

    std::fstream colliderFile;
    colliderFile.open(colliderMapPath);

    if (!colliderFile.is_open())
    {
        // Silence here used to look like a broken tilemap: every tile fell
        // back to the first cell of the sheet, so the whole map came out as
        // one repeated tile instead of saying the file was missing.
        Logger::Err(
            "Could not open the colliderMap file '" + colliderMapPath +
            "'. No tiles were created. Check tilemap.map_file in level.lua, and "
            "note that the default Visual Studio .gitignore ignores *.map, so the "
            "file may never have been committed."
        );
    }

	if (!mapFile.is_open())
	{
		// Silence here used to look like a broken tilemap: every tile fell
		// back to the first cell of the sheet, so the whole map came out as
		// one repeated tile instead of saying the file was missing.
		Logger::Err(
			"Could not open the tilemap file '" + mapFilePath +
			"'. No tiles were created. Check tilemap.map_file in level.lua, and "
			"note that the default Visual Studio .gitignore ignores *.map, so the "
			"file may never have been committed."
		);
	}
	else
	{
		bool tilemap_ok = true;
		bool unexpected_character = false;
		int tiles_created = 0;

		// Reads the next tile digit, stepping over any separator: commas,
		// spaces, carriage returns and newlines alike.
		//
		// Counting separators instead would tie the loader to the line endings
		// the file happens to carry. A CRLF map parsed on Windows only, where
		// text mode quietly folds the carriage return away, and broke on Linux
		// and macOS where it does not.
		auto next_digit = [&mapFile, &unexpected_character](char& digit) {

			char character = '\0';

			while (mapFile.get(character)) {

				if (character >= '0' && character <= '9') {
					digit = character;
					return true;
				}

				if (character == ',' || character == ' ' || character == '\t' ||
					character == '\r' || character == '\n') {
					continue;
				}

				unexpected_character = true;
				return false;
			}

			return false;
		};

	    auto next_binary_digit = [&colliderFile, &unexpected_character](char& binary_digit) {

	        char character = '\0';

	        while (colliderFile.get(character)) {

	            if (character >= '0' && character <= '9') {
	                binary_digit = character;
	                return true;
	            }

	            if (character == ',' || character == ' ' || character == '\t' ||
                    character == '\r' || character == '\n') {
	                continue;
                    }

	            unexpected_character = true;
	            return false;
	        }

	        return false;
	    };

		for (int y = 0; y < map_num_rows && tilemap_ok; y++) {
			for (int x = 0; x < map_num_cols; x++) {

				// Each tile is two digits: the row and the column of the
				// cell inside the tileset.
				char row_digit = '\0';
				char column_digit = '\0';

			    char collider_row_digit = '\0';
			    char collider_column_digit = '\0';

				if (!next_digit(row_digit) || !next_digit(column_digit)) {
					Logger::Err(
						"The tilemap file '" + mapFilePath + "' " +
						(unexpected_character
							? std::string("has an unexpected character at row ")
							: std::string("ran out of data at row ")) +
						std::to_string(y) + ", column " + std::to_string(x) + ". Expected " +
						std::to_string(map_num_rows) + " rows of " +
						std::to_string(map_num_cols) + " tiles, two digits each."
					);

					tilemap_ok = false;
					break;
				}

			    if (!next_binary_digit(collider_row_digit) || !next_binary_digit(collider_column_digit)) {
			        Logger::Err(
                        "The tilemap file '" + colliderMapPath + "' " +
                        (unexpected_character
                            ? std::string("has an unexpected character at row ")
                            : std::string("ran out of data at row ")) +
                        std::to_string(y) + ", column " + std::to_string(x) + ". Expected " +
                        std::to_string(map_num_rows) + " rows of " +
                        std::to_string(map_num_cols) + " tiles, two digits each."
                    );

			        tilemap_ok = false;
			        break;
			    }

				int sprite_rect_y = (row_digit - '0') * tile_size;
				int sprite_rect_x = (column_digit - '0') * tile_size;

				Entity tile = registry->createEntity();

				tile.group("tiles");
			    //binary representation of '0' (our default value) is 48. Whenever the map file has a 01 which would mean it has a collider there would add 1 to this making it 49
			    //checking if this value equals 49 is the same as checking if it is equal to 01 in the map file
			    if (collider_column_digit == 49) {
			        tile.addComponent<BoxColliderComponent>(raylib::Vector2(tile_size * tile_scale, tile_size * tile_scale));
			        Logger::Log("Box collider added");
			    }

				tile.addComponent<TransformComponent>(raylib::Vector2(x * (tile_scale * tile_size), y * (tile_scale * tile_size)), raylib::Vector2(tile_scale, tile_scale));
				tile.addComponent<SpriteComponent>(mapTextureAssetId, raylib::Vector2(tile_size, tile_size), raylib::Vector2(tile_size, tile_size), raylib::Vector2(sprite_rect_x, sprite_rect_y));
				tiles_created++;
			}
		}

		mapFile.close();
        colliderFile.close();
		if (tilemap_ok) {
			Logger::Log("Tilemap loaded from '" + mapFilePath + "': " + std::to_string(tiles_created) + " tiles.");
		}
	}
	game.map_width_ = map_num_cols * tile_size * tile_scale;
	game.map_height_ = map_num_rows * tile_size * tile_scale;

    /////////////////////////////////////////////////////////////////
    // Entities
    /////////////////////////////////////////////////////////////////

    sol::optional<sol::table> entities_opt = level["entities"];

    if (entities_opt == sol::nullopt)
        return;

    sol::table entities = entities_opt.value();

    for (auto& pair : entities)
    {
        sol::object object = pair.second;

        if (!object.is<sol::table>())
            continue;

        sol::table entity = object.as<sol::table>();

        Entity new_entity = registry->createEntity();


        /////////////////////////////////////////////////////////////
        // Tag
        /////////////////////////////////////////////////////////////

        sol::optional<std::string> tag = entity["tag"];

        if (tag != sol::nullopt)
        {
            new_entity.tag(tag.value());
        }


        /////////////////////////////////////////////////////////////
        // Group
        /////////////////////////////////////////////////////////////

        sol::optional<std::string> group = entity["group"];

        if (group != sol::nullopt)
        {
            new_entity.group(group.value());
        }


        /////////////////////////////////////////////////////////////
        // Components
        /////////////////////////////////////////////////////////////

        sol::optional<sol::table> components_opt =
            entity["components"];

        if (components_opt == sol::nullopt)
            continue;

        sol::table components = components_opt.value();


        /////////////////////////////////////////////////////////////
        // Transform
        /////////////////////////////////////////////////////////////

        sol::optional<sol::table> transform_opt =
            components["transform"];

        if (transform_opt != sol::nullopt)
        {
            sol::table transform = transform_opt.value();

            sol::table position = transform["position"];
            sol::table size = transform["size"];

            float x = position["x"].get_or(0.0f);
            float y = position["y"].get_or(0.0f);
            float width = size["x"].get_or(0.0f);
            float height = size["y"].get_or(0.0f);


            new_entity.addComponent<TransformComponent>(
                raylib::Vector2(x, y),
                raylib::Vector2(width, height)
            );
        }


        /////////////////////////////////////////////////////////////
        // RigidBody
        /////////////////////////////////////////////////////////////

        sol::optional<sol::table> rigidbody_opt =
            components["rigidbody"];

        if (rigidbody_opt != sol::nullopt)
        {
            sol::table rigidbody = rigidbody_opt.value();

            sol::table velocity = rigidbody["velocity"];

            float velocity_x =
                velocity["x"].get_or(0.0f);

            float velocity_y =
                velocity["y"].get_or(0.0f);

            bool is_static =
                rigidbody["is_static"].get_or(false);

            float mass =
                rigidbody["mass"].get_or(1.0f);

            float bounce =
                rigidbody["bounce"].get_or(0.5f);

            new_entity.addComponent<RigidBodyComponent>(
                sf::Vector2f(velocity_x, velocity_y),
                is_static,
                mass,
                bounce
            );
        }


        /////////////////////////////////////////////////////////////
        // Shape
        //
        // A primitive: geometry plus a solid color, and nothing else.
        // Anything that needs an image belongs in the "sprite" block below.
        // An entity may declare both.
        /////////////////////////////////////////////////////////////

        sol::optional<sol::table> shape_opt =
            components["shape"];

        if (shape_opt != sol::nullopt)
        {
            sol::table shape = shape_opt.value();

            float width =
                shape["width"].get_or(32.0f);

            float height =
                shape["height"].get_or(32.0f);

            std::string shape_type =
                shape["type"].get_or(
                    std::string("rectangle")
                );

            ShapeType type = ShapeType::rectangle;

            if (shape_type == "circle")
            {
                type = ShapeType::circle;
            }


            // Default white
            int r = 255;
            int g = 255;
            int b = 255;
            int a = 255;

            sol::optional<sol::table> color_opt =
                shape["color"];

            if (color_opt != sol::nullopt)
            {
                sol::table color = color_opt.value();

                r = color["r"].get_or(255);
                g = color["g"].get_or(255);
                b = color["b"].get_or(255);
                a = color["a"].get_or(255);
            }

            bool fixed =
                shape["fixed"].get_or(false);

            // Shapes are untextured now. Say so out loud instead of
            // silently dropping an asset id an old level still declares.
            sol::optional<std::string> stray_texture_opt =
                shape["texture_asset_id"];

            if (stray_texture_opt != sol::nullopt)
            {
                Logger::Err(
                    "Entity id " + std::to_string(new_entity.getId()) +
                    ": the shape block declares texture_asset_id '" +
                    stray_texture_opt.value() +
                    "', which is ignored. Move it to a sprite block."
                );
            }

            new_entity.addComponent<ShapeComponent>(
                sf::Vector2f(width, height),
                type,
                sf::Color(r, g, b, a),
                fixed
            );
        }


        /////////////////////////////////////////////////////////////
        // Sprite
        //
        // A textured quad taken from the asset store. width / height are
        // the size it is drawn at; source_width / source_height and
        // src_rect_x / src_rect_y pick the frame inside the texture.
        /////////////////////////////////////////////////////////////

        sol::optional<sol::table> sprite_opt =
            components["sprite"];

        if (sprite_opt != sol::nullopt)
        {
            sol::table sprite = sprite_opt.value();
            //Logger::Log("Added Sprite Component");
            std::string texture =
                sprite["texture_asset_id"];

            float width =
                sprite["width"].get_or(0.0f);

            float height =
                sprite["height"].get_or(0.0f);

            int source_width =
                sprite["source_width"].get_or(
                    static_cast<int>(width)
                );

            int source_height =
                sprite["source_height"].get_or(
                    static_cast<int>(height)
                );

            int src_x =
                sprite["src_rect_x"].get_or(0);

            int src_y =
                sprite["src_rect_y"].get_or(0);

            bool fixed =
                sprite["fixed"].get_or(false);


            // Optional tint, multiplied with the texture. White leaves
            // the artwork untouched.
            int r = 255;
            int g = 255;
            int b = 255;
            int a = 255;

            sol::optional<sol::table> tint_opt =
                sprite["color"];

            if (tint_opt != sol::nullopt)
            {
                sol::table tint = tint_opt.value();

                r = tint["r"].get_or(255);
                g = tint["g"].get_or(255);
                b = tint["b"].get_or(255);
                a = tint["a"].get_or(255);
            }

            new_entity.addComponent<SpriteComponent>(
                texture,
                raylib::Vector2(width, height),
                raylib::Vector2(
                    source_width,
                    source_height
                ),
                raylib::Vector2(src_x, src_y),
                fixed,
                raylib::Color(r, g, b, a)
            );
        }


        /////////////////////////////////////////////////////////////
        // Animation
        /////////////////////////////////////////////////////////////

        sol::optional<sol::table> animation_opt =
            components["animation"];

        if (animation_opt != sol::nullopt)
        {
            sol::table animation =
                animation_opt.value();

            int num_frames =
                animation["num_frames"].get_or(1);

            int start_frame =
                animation["start_frame"].get_or(1);

            int speed_rate =
                animation["speed_rate"].get_or(1);

            int num_rows =
                animation["speed_rate"].get_or(5);

            bool loop =
                animation["loop"].get_or(true);

            new_entity.addComponent<AnimationComponent>(
                num_frames,
                start_frame,
                speed_rate,
                loop
            );
        }


        /////////////////////////////////////////////////////////////
        // BoxCollider
        /////////////////////////////////////////////////////////////

        sol::optional<sol::table> collider_opt =
            components["boxcollider"];

        if (collider_opt != sol::nullopt)
        {
            sol::table collider =
                collider_opt.value();

            float width =
                collider["width"].get_or(0.0f);

            float height =
                collider["height"].get_or(0.0f);

            float x = collider["x"].get_or(0.0f);

            float y = collider["y"].get_or(0.0f);

            new_entity.addComponent<BoxColliderComponent>(
                raylib::Vector2(width, height),
                raylib::Vector2(x, y)
            );
        }


        /////////////////////////////////////////////////////////////
        // Health
        /////////////////////////////////////////////////////////////

        sol::optional<sol::table> health_opt =
            components["health"];

        if (health_opt != sol::nullopt)
        {
            sol::table health = health_opt.value();

            int health_percentage =
                health["health_percentage"].get_or(100);

            new_entity.addComponent<HealthComponent>(
                health_percentage
            );
        }


        /////////////////////////////////////////////////////////////
        // Camera Follow
        /////////////////////////////////////////////////////////////

        sol::optional<sol::table> camera_follow_opt =
            components["camera_follow"];

        if (camera_follow_opt != sol::nullopt)
        {
            new_entity.addComponent<CameraFollowComponent>();
        }


        /////////////////////////////////////////////////////////////
        // Keyboard Controller
        /////////////////////////////////////////////////////////////

        sol::optional<sol::table> keyboard_opt =
            components["keyboard_controller"];

        if (keyboard_opt != sol::nullopt)
        {
            sol::table keyboard =
                keyboard_opt.value();

            sol::table up =
                keyboard["up_velocity"];

            sol::table right =
                keyboard["right_velocity"];

            sol::table down =
                keyboard["down_velocity"];

            sol::table left =
                keyboard["left_velocity"];

            new_entity.addComponent<KeyboardControlledComponent>(
                sf::Vector2f(
                    up["x"].get_or(0.0f),
                    up["y"].get_or(0.0f)
                ),

                sf::Vector2f(
                    right["x"].get_or(0.0f),
                    right["y"].get_or(0.0f)
                ),

                sf::Vector2f(
                    down["x"].get_or(0.0f),
                    down["y"].get_or(0.0f)
                ),

                sf::Vector2f(
                    left["x"].get_or(0.0f),
                    left["y"].get_or(0.0f)
                )
            );
        }

        /////////////////////////////////////////////////////////////
        // Player Component
        /////////////////////////////////////////////////////////////
        sol::optional<sol::table> player_opt =
        components["player"];

        if (player_opt != sol::nullopt)
        {
            sol::table player = player_opt.value();
            int speed = player["speed"].get_or(2);
            new_entity.addComponent<MoveableComponent>(speed);
        }


        /////////////////////////////////////////////////////////////
        // Projectile Emitter
        /////////////////////////////////////////////////////////////

        sol::optional<sol::table> projectile_opt =
            components["projectile_emitter"];

        if (projectile_opt != sol::nullopt)
        {
            sol::table projectile =
                projectile_opt.value();

            sol::table velocity =
                projectile["projectile_velocity"];

            float velocity_x =
                velocity["x"].get_or(0.0f);

            float velocity_y =
                velocity["y"].get_or(0.0f);

            int repeat_frequency =
                projectile["repeat_frequency"].get_or(0);

            int projectile_duration =
                projectile["projectile_duration"].get_or(10);

            int hit_percentage_damage =
                projectile["hit_percentage_damage"].get_or(10);

            bool friendly =
                projectile["friendly"].get_or(false);

            new_entity.addComponent<ProjectileEmitterComponent>(
                sf::Vector2f(
                    velocity_x,
                    velocity_y
                ),
                repeat_frequency,
                projectile_duration,
                hit_percentage_damage,
                friendly,

                // Your current component takes two additional
                // parameters compared with the reference project.
                // These match the defaults you already use.
                0,
                false
            );
        }
    }

    // TEXT EXAMPLE
    Entity label = registry->createEntity();
    sf::Color green = { 0, 255, 0 };
    label.addComponent<TextLabelComponent>(sf::Vector2f(game.window_width_ / 2, 10), "CHOPPER 1.0", "charriot-font", green, 24, true);

}
