#pragma once
#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "../ECS/ECS.h"
#include "../Game/game.h"

#include "../Components/TransformComponent.h"
#include "../Components/ShapeComponent.h"
#include "../Components/SpriteComponent.h"
#include "../Components/AnimationComponent.h"
#include "../Components/RigidBodyComponent.h"
#include "../Components/BoxColliderComponent.h"
#include "../Components/HealthComponent.h"
#include "../Components/KeyboardControlledComponent.h"
#include "../Components/CameraFollowComponent.h"
#include "../Components/ProjectileComponent.h"
#include "../Components/ProjectileEmitterComponent.h"
#include "../Components/TextLabelComponent.h"

#include "imgui.h"
#include "imgui-SFML.h"

class RenderGUISystem : public System
{
public:
	RenderGUISystem() = default;

	void update(sf::RenderWindow& window, Game& game)
	{
		ImGui::Begin("Game Settings / Entity Editor");

		if (ImGui::CollapsingHeader("Game"))
		{
			ImGui::Checkbox("Gravity", &game.gravity);
			ImGui::SameLine();
			ImGui::Checkbox("Show colliders", &game.show_colliders);

			if (ImGui::Button("Reset level"))
			{
				game.requestLevelReset();
			}
			ImGui::SameLine();
			ImGui::TextDisabled("reloads %s", game.currentLevel().c_str());

			ImGui::TextDisabled(
				"Window %u x %u   Map %u x %u",
				game.window_width_, game.window_height_,
				game.map_width_, game.map_height_
			);
		}

		ImGui::SeparatorText("Entities");

		std::vector<Entity> entities;

		for (auto entity : getSystemEntities())
		{
			entities.push_back(entity);
		}

		if (entities.empty())
		{
			ImGui::TextDisabled("Nothing to edit with the current filters.");
		}
		else
		{
			// The selection follows the entity id rather than its place in the
			// list, so it survives entities spawning and dying around it.
			int selected_index = 0;

			for (int i = 0; i < static_cast<int>(entities.size()); i++)
			{
				if (entities[i].getId() == selected_entity_id_)
				{
					selected_index = i;
					break;
				}
			}

			Entity selected = entities[selected_index];
			selected_entity_id_ = selected.getId();

			if (ImGui::BeginCombo("Selected entity", entityLabel(selected).c_str()))
			{
				for (int i = 0; i < static_cast<int>(entities.size()); i++)
				{
					const bool is_selected = (i == selected_index);

					if (ImGui::Selectable(entityLabel(entities[i]).c_str(), is_selected))
					{
						selected_entity_id_ = entities[i].getId();
					}

					if (is_selected) ImGui::SetItemDefaultFocus();
				}

				ImGui::EndCombo();
			}

			ImGui::TextDisabled("Holds: %s", componentSummary(selected).c_str());

			drawTransform(selected);
			drawShape(selected);
			drawSprite(selected);
			drawAnimation(selected);
			drawRigidBody(selected);
			drawBoxCollider(selected);
			drawHealth(selected);
			drawKeyboardControl(selected);
			drawCameraFollow(selected);
			drawProjectileEmitter(selected);
			drawProjectile(selected);
			drawTextLabel(selected);
		}

		ImGui::End();

		ImGui::SFML::Render(window);
	}

private:
	int selected_entity_id_ = -1;
	bool show_tiles_ = false;
	bool show_projectiles_ = false;

	// Hard clamp, including ctrl+click typed input
	static constexpr ImGuiSliderFlags kClamp = ImGuiSliderFlags_AlwaysClamp;


	/////////////////////////////////////////////////////////////////////////
	// Helpers
	/////////////////////////////////////////////////////////////////////////

	// A value a system owns: shown so it can be watched, never edited here.
	static void readOnlyRow(const char* label, const std::string& value)
	{
		ImGui::TextDisabled("%s: %s", label, value.c_str());
	}

	static void note(const char* text)
	{
		ImGui::TextDisabled("  %s", text);
	}

	static std::string number(float value)
	{
		char buffer[32];
		std::snprintf(buffer, sizeof(buffer), "%.2f", value);
		return buffer;
	}

	static std::string entityLabel(Entity entity)
	{
		std::string label = std::to_string(entity.getId());

		if (entity.belongsToGroup("tiles"))            label += " (tile)";
		else if (entity.belongsToGroup("projectiles")) label += " (projectile)";
		else if (entity.hasComponent<SpriteComponent>() && entity.hasComponent<ShapeComponent>()) label += " (sprite + shape)";
		else if (entity.hasComponent<SpriteComponent>()) label += " (sprite)";
		else if (entity.hasComponent<ShapeComponent>())  label += " (shape)";
		else if (entity.hasComponent<TextLabelComponent>()) label += " (text)";

		return label;
	}

	// One line naming every component on the entity, so nothing is hidden
	static std::string componentSummary(Entity entity)
	{
		std::string summary;

		auto add = [&summary](bool present, const char* name)
		{
			if (!present) return;
			if (!summary.empty()) summary += ", ";
			summary += name;
		};

		add(entity.hasComponent<TransformComponent>(), "Transform");
		add(entity.hasComponent<ShapeComponent>(), "Shape");
		add(entity.hasComponent<SpriteComponent>(), "Sprite");
		add(entity.hasComponent<AnimationComponent>(), "Animation");
		add(entity.hasComponent<RigidBodyComponent>(), "RigidBody");
		add(entity.hasComponent<BoxColliderComponent>(), "BoxCollider");
		add(entity.hasComponent<HealthComponent>(), "Health");
		add(entity.hasComponent<KeyboardControlledComponent>(), "KeyboardControlled");
		add(entity.hasComponent<CameraFollowComponent>(), "CameraFollow");
		add(entity.hasComponent<ProjectileEmitterComponent>(), "ProjectileEmitter");
		add(entity.hasComponent<ProjectileComponent>(), "Projectile");
		add(entity.hasComponent<TextLabelComponent>(), "TextLabel");

		return summary.empty() ? "no components" : summary;
	}

	// Keep the collider matching the visual size while a slider is dragged
	static void syncCollider(Entity entity, const sf::Vector2f& size)
	{
		if (!entity.hasComponent<BoxColliderComponent>()) return;

		entity.getComponent<BoxColliderComponent>().size_ = size;
	}


	/////////////////////////////////////////////////////////////////////////
	// Component panels
	/////////////////////////////////////////////////////////////////////////

	static void drawTransform(Entity e)
	{
		if (!e.hasComponent<TransformComponent>()) return;
		if (!ImGui::CollapsingHeader("Transform")) return;

		auto& transform = e.getComponent<TransformComponent>();

		float position[2] = { transform.position_.x, transform.position_.y };
		if (ImGui::DragFloat2("Position##transform", position, 1.f, -10000.f, 10000.f, "%.1f", kClamp))
		{
			transform.position_.x = position[0];
			transform.position_.y = position[1];
		}

		float scale[2] = { transform.scale_.x, transform.scale_.y };
		if (ImGui::DragFloat2("Scale##transform", scale, 0.05f, 0.1f, 20.f, "%.2f", kClamp))
		{
			transform.scale_.x = scale[0];
			transform.scale_.y = scale[1];
		}

		ImGui::SliderFloat("Rotation##transform", &transform.rotation_, 0.f, 360.f, "%.1f deg", kClamp);
	}

	static void drawShape(Entity e)
	{
		if (!e.hasComponent<ShapeComponent>()) return;
		if (!ImGui::CollapsingHeader("Shape")) return;

		auto& shape = e.getComponent<ShapeComponent>();

		ImGui::Checkbox("Draw##shape", &shape.visible_);
		ImGui::SameLine();
		ImGui::Checkbox("Ignore camera##shape", &shape.is_fixed_);

		int type = static_cast<int>(shape.type_);
		if (ImGui::Combo("Type##shape", &type, "Rectangle\0Circle\0"))
		{
			shape.type_ = static_cast<ShapeType>(type);
		}

		if (shape.type_ == ShapeType::circle)
		{
			float diameter = shape.size_.x;

			if (ImGui::SliderFloat("Diameter##shape", &diameter, 2.f, 512.f, "%.0f", kClamp))
			{
				shape.size_.x = diameter;
				shape.size_.y = diameter;

				syncCollider(e, { diameter, diameter });
			}
		}
		else
		{
			float size[2] = { shape.size_.x, shape.size_.y };

			if (ImGui::DragFloat2("Size##shape", size, 1.f, 1.f, 1024.f, "%.0f", kClamp))
			{
				shape.size_.x = size[0];
				shape.size_.y = size[1];

				syncCollider(e, { size[0], size[1] });
			}
		}

		float color[3] = { shape.color_.r / 255.f, shape.color_.g / 255.f, shape.color_.b / 255.f };
		if (ImGui::ColorEdit3("Color##shape", color))
		{
			shape.color_.r = static_cast<std::uint8_t>(color[0] * 255.f);
			shape.color_.g = static_cast<std::uint8_t>(color[1] * 255.f);
			shape.color_.b = static_cast<std::uint8_t>(color[2] * 255.f);
		}
	}

	static void drawSprite(Entity e)
	{
		if (!e.hasComponent<SpriteComponent>()) return;
		if (!ImGui::CollapsingHeader("Sprite")) return;

		auto& sprite = e.getComponent<SpriteComponent>();

		ImGui::Checkbox("Draw##sprite", &sprite.visible_);
		ImGui::SameLine();
		ImGui::Checkbox("Ignore camera##sprite", &sprite.is_fixed_);

		// Read-only: a texture id nothing in the asset store answers to would
		// leave the entity invisible with no hint why.
		readOnlyRow("Texture", sprite.asset_id_.empty() ? "(none)" : sprite.asset_id_);

		float size[2] = { sprite.size_.x, sprite.size_.y };
		if (ImGui::DragFloat2("Drawn size##sprite", size, 1.f, 1.f, 1024.f, "%.0f", kClamp))
		{
			sprite.size_.x = size[0];
			sprite.size_.y = size[1];

			syncCollider(e, { size[0], size[1] });
		}

		int source_size[2] = { sprite.src_size_.x, sprite.src_size_.y };
		if (ImGui::DragInt2("Source size##sprite", source_size, 1.f, 0, 4096, "%d", kClamp))
		{
			sprite.src_size_.x = source_size[0];
			sprite.src_size_.y = source_size[1];
		}
		note("source size 0 means the whole texture");

		// The animation system walks the source position along x, and the
		// keyboard system picks a row with y. Editing it by hand under those
		// systems would be overwritten on the next frame.
		const bool source_position_is_driven =
			e.hasComponent<AnimationComponent>() ||
			e.hasComponent<KeyboardControlledComponent>();

		if (source_position_is_driven)
		{
			readOnlyRow(
				"Source position",
				std::to_string(sprite.src_position_.x) + ", " + std::to_string(sprite.src_position_.y)
			);
			note("driven every frame by the animation / keyboard systems");
		}
		else
		{
			int source_position[2] = { sprite.src_position_.x, sprite.src_position_.y };
			if (ImGui::DragInt2("Source position##sprite", source_position, 1.f, 0, 4096, "%d", kClamp))
			{
				sprite.src_position_.x = source_position[0];
				sprite.src_position_.y = source_position[1];
			}
		}

		float tint[3] = { sprite.tint_.r / 255.f, sprite.tint_.g / 255.f, sprite.tint_.b / 255.f };
		if (ImGui::ColorEdit3("Tint##sprite", tint))
		{
			sprite.tint_.r = static_cast<std::uint8_t>(tint[0] * 255.f);
			sprite.tint_.g = static_cast<std::uint8_t>(tint[1] * 255.f);
			sprite.tint_.b = static_cast<std::uint8_t>(tint[2] * 255.f);
		}
	}

	static void drawAnimation(Entity e)
	{
		if (!e.hasComponent<AnimationComponent>()) return;
		if (!ImGui::CollapsingHeader("Animation")) return;

		auto& animation = e.getComponent<AnimationComponent>();

		if (ImGui::SliderInt("Frames##anim", &animation.num_frames_, 1, 64, "%d", kClamp))
		{
			// Keep the playhead inside the new frame count, so the sprite
			// never samples past the end of its sheet
			if (animation.current_frame_ >= animation.num_frames_)
			{
				animation.current_frame_ = animation.num_frames_ - 1;
			}
		}

		ImGui::SliderInt("Ticks per frame##anim", &animation.ticks_per_frame_, 0, 120, "%d", kClamp);
		note("0 advances a frame every tick");

		ImGui::Checkbox("Loop##anim", &animation.is_loop_);
		note("stored, but the animation system always loops today");

		readOnlyRow("Current frame", std::to_string(animation.current_frame_));
		readOnlyRow("Tick counter", std::to_string(animation.tick_counter_));
	}

	static void drawRigidBody(Entity e)
	{
		if (!e.hasComponent<RigidBodyComponent>()) return;
		if (!ImGui::CollapsingHeader("RigidBody")) return;

		auto& rigidbody = e.getComponent<RigidBodyComponent>();

		if (ImGui::Checkbox("Static##rb", &rigidbody.is_static_))
		{
			// Mirror what the constructor does, so mass and its inverse can
			// never disagree with the static flag
			if (rigidbody.is_static_)
			{
				rigidbody.mass_ = 0.f;
				rigidbody.inv_mass_ = 0.f;
			}
			else
			{
				if (rigidbody.mass_ <= 0.f) rigidbody.mass_ = 1.f;
				rigidbody.inv_mass_ = 1.f / rigidbody.mass_;
			}
		}

		float velocity[2] = { rigidbody.velocity_.x, rigidbody.velocity_.y };
		if (ImGui::DragFloat2("Velocity##rb", velocity, 1.f, -1000.f, 1000.f, "%.1f", kClamp))
		{
			rigidbody.velocity_.x = velocity[0];
			rigidbody.velocity_.y = velocity[1];
		}

		if (rigidbody.is_static_)
		{
			readOnlyRow("Mass", "infinite (static body)");
		}
		else
		{
			if (ImGui::SliderFloat("Mass##rb", &rigidbody.mass_, 0.1f, 100.f, "%.2f", kClamp))
			{
				rigidbody.inv_mass_ = 1.f / rigidbody.mass_;
			}
		}

		ImGui::SliderFloat("Bounciness##rb", &rigidbody.e_, 0.f, 1.f, "%.2f", kClamp);

		readOnlyRow("Inverse mass", number(rigidbody.inv_mass_));
	}

	static void drawBoxCollider(Entity e)
	{
		if (!e.hasComponent<BoxColliderComponent>()) return;
		if (!ImGui::CollapsingHeader("BoxCollider")) return;

		auto& collider = e.getComponent<BoxColliderComponent>();

		float size[2] = { collider.size_.x, collider.size_.y };
		if (ImGui::DragFloat2("Size##collider", size, 1.f, 1.f, 1024.f, "%.0f", kClamp))
		{
			collider.size_.x = size[0];
			collider.size_.y = size[1];
		}

		note("resizing a shape or sprite above resizes this too");
	}

	static void drawHealth(Entity e)
	{
		if (!e.hasComponent<HealthComponent>()) return;
		if (!ImGui::CollapsingHeader("Health")) return;

		auto& health = e.getComponent<HealthComponent>();

		ImGui::SliderInt("Percentage##health", &health.health_percentage_, 1, 100, "%d", kClamp);
		note("the damage system kills the entity at 0, so the editor stops at 1");
	}

	static void drawKeyboardControl(Entity e)
	{
		if (!e.hasComponent<KeyboardControlledComponent>()) return;
		if (!ImGui::CollapsingHeader("KeyboardControlled")) return;

		auto& keyboard = e.getComponent<KeyboardControlledComponent>();

		auto velocityRow = [](const char* label, sf::Vector2f& velocity)
		{
			float value[2] = { velocity.x, velocity.y };

			if (ImGui::DragFloat2(label, value, 1.f, -1000.f, 1000.f, "%.1f", kClamp))
			{
				velocity.x = value[0];
				velocity.y = value[1];
			}
		};

		velocityRow("Up##kb", keyboard.upVelocity_);
		velocityRow("Right##kb", keyboard.rightVelocity_);
		velocityRow("Down##kb", keyboard.downVelocity_);
		velocityRow("Left##kb", keyboard.leftVelocity_);

		readOnlyRow(
			"Facing",
			std::to_string(static_cast<int>(keyboard.facing_.x)) + ", " +
			std::to_string(static_cast<int>(keyboard.facing_.y))
		);
		note("set by the arrow keys; a stationary entity shoots this way");
	}

	static void drawCameraFollow(Entity e)
	{
		if (!e.hasComponent<CameraFollowComponent>()) return;
		if (!ImGui::CollapsingHeader("CameraFollow")) return;

		note("no parameters: the camera movement system keeps this entity centred");
	}

	static void drawProjectileEmitter(Entity e)
	{
		if (!e.hasComponent<ProjectileEmitterComponent>()) return;
		if (!ImGui::CollapsingHeader("ProjectileEmitter")) return;

		auto& emitter = e.getComponent<ProjectileEmitterComponent>();

		float velocity[2] = { emitter.projectile_velocity_.x, emitter.projectile_velocity_.y };
		if (ImGui::DragFloat2("Projectile velocity##emitter", velocity, 1.f, -1000.f, 1000.f, "%.1f", kClamp))
		{
			emitter.projectile_velocity_.x = velocity[0];
			emitter.projectile_velocity_.y = velocity[1];
		}

		ImGui::SliderInt("Repeat frequency##emitter", &emitter.repeat_frequency_, 0, 60, "%d s", kClamp);
		note("0 stops automatic fire; the player still shoots with space");

		ImGui::SliderInt("Projectile lifetime##emitter", &emitter.projectile_duration_, 1, 60, "%d s", kClamp);
		ImGui::SliderInt("Hit damage##emitter", &emitter.hit_percent_damage_, 0, 100, "%d %%", kClamp);
		ImGui::Checkbox("Friendly##emitter", &emitter.is_friendly_);
		note("friendly shots damage enemies, hostile ones damage the player");

		readOnlyRow("Since last shot", number(emitter.elapsed_since_last_emission_) + " s");
	}

	static void drawProjectile(Entity e)
	{
		if (!e.hasComponent<ProjectileComponent>()) return;
		if (!ImGui::CollapsingHeader("Projectile")) return;

		auto& projectile = e.getComponent<ProjectileComponent>();

		readOnlyRow("Friendly", projectile.is_friendly_ ? "yes" : "no");
		readOnlyRow("Hit damage", std::to_string(projectile.hit_percent_damage_) + " %");

		ImGui::SliderFloat("Lifetime##projectile", &projectile.duration_, 0.1f, 60.f, "%.1f s", kClamp);

		readOnlyRow("Age", number(projectile.elapsed_time_) + " s");
		note("the lifecycle system kills this projectile once its age passes its lifetime");
	}

	static void drawTextLabel(Entity e)
	{
		if (!e.hasComponent<TextLabelComponent>()) return;
		if (!ImGui::CollapsingHeader("TextLabel")) return;

		auto& label = e.getComponent<TextLabelComponent>();

		char text[256];
		std::snprintf(text, sizeof(text), "%s", label.text_.c_str());

		if (ImGui::InputText("Text##label", text, sizeof(text)))
		{
			label.text_ = text;
		}

		float position[2] = { label.position_.x, label.position_.y };
		if (ImGui::DragFloat2("Position##label", position, 1.f, -10000.f, 10000.f, "%.1f", kClamp))
		{
			label.position_.x = position[0];
			label.position_.y = position[1];
		}

		ImGui::SliderInt("Character size##label", &label.size_, 4, 128, "%d px", kClamp);
		ImGui::Checkbox("Ignore camera##label", &label.is_fixed_);

		float color[3] = { label.color_.r / 255.f, label.color_.g / 255.f, label.color_.b / 255.f };
		if (ImGui::ColorEdit3("Color##label", color))
		{
			label.color_.r = static_cast<std::uint8_t>(color[0] * 255.f);
			label.color_.g = static_cast<std::uint8_t>(color[1] * 255.f);
			label.color_.b = static_cast<std::uint8_t>(color[2] * 255.f);
		}
	}
};
