#pragma once
#include <SFML/Graphics.hpp>

#include "../ECS/ECS.h"
#include "../EventBus/EventBus.h"
#include "../AssetStore/AssetStore.h"
#include <sol.hpp>
#include <raylib.h>
#include "raylib-cpp.hpp"

const int FPS = 30;
const float kGravity = 9.8f;

const double kSecondsPerFrame =
1.0 / static_cast<double>(FPS);

const double kMilisecsPerFrame =
1000.0 / static_cast<double>(FPS);

class Game
{
private:
	bool is_running_;
	//sf::Clock game_clock_;

	// sf::Time elapse_time_;
	// sf::RenderWindow window_;
	// sf::IntRect camera;
	raylib::Camera2D camera;
	raylib::Window window;
	sol::state lua_;
	raylib::Texture2D texture;
	bool player_moving_;
	int direction;

	int key;

	std::unique_ptr<Registry> registry_;
	std::unique_ptr<EventBus> event_bus_;
	std::unique_ptr<AssetStore> asset_store_;

	// Level currently loaded, and a reset queued by the editor. The reset is
	// deferred to the start of the next update, because the editor asks for
	// it from inside a system that the reset destroys.
	std::string current_level_;
	bool level_reset_requested_;

	void loadLevel();

public:
	
	Game();
	~Game();
	
	void initialize();
	void run();
	void processInput();
	void setup();
	void update();
	void render();
	void destroy();

	unsigned int window_width_;
	unsigned int window_height_;
	unsigned int map_width_;
	unsigned int map_height_;
	bool gravity;
	bool show_colliders;

	// Throws away every entity and loads the current level again from its
	// Lua file. Safe to call from inside a system: it takes effect next frame.
	void requestLevelReset() { level_reset_requested_ = true; }
	const std::string& currentLevel() const { return current_level_; }
};