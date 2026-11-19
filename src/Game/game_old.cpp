#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

#include "game.h"
#include "../Logger/Logger.h"
#include "LevelLoader.h"
#include "../Components/TransformComponent.h"
#include "../Components/RigidBodyComponent.h"
#include "../Components/BoxColliderComponent.h"
#include "../Components/AnimationComponent.h"
#include "../Components/CameraFollowComponent.h"

#include "../Systems/MovementSystem.h"
#include "../Systems/RenderSpriteSystem.h"
#include "../Systems/RenderShapeSystem.h"
#include "../Systems/ColliderSystem.h"
#include "../Systems/DamageSystem.h"
#include "../Systems/KeyboardControlSystem.h"
#include "../Systems/AnimationSystem.h"
#include "../Systems/RenderGUISystem.h"
#include "../Systems/RenderColliderSystem.h"
#include "../Systems/CameraMovementSystem.h"
#include "../Systems/ProjectileEmitSystem.h"
#include "../Systems/ProjectileLifecycleSystem.h"
#include "../Systems/RenderTextSystem.h"
#include "../Systems/RenderHealthBarSystem.h"

#include "../Events/KeyPressedEvent.h"

#include "imgui.h"
#include "imgui-SFML.h"
#import "raylib.h"
#include "raylib-cpp.hpp"

Game::Game()
{
	is_running_ = false;
	level_reset_requested_ = false;

	// These were left uninitialised before, so gravity started out as
	// whatever happened to be in memory
	gravity = false;
	show_colliders = true;
	window_width_ = 800;
	window_height_ = 600;
	map_width_ = 0;
	map_height_ = 0;

	registry_ = std::make_unique<Registry>();
	event_bus_ = std::make_unique<EventBus>();
	asset_store_ = std::make_unique<AssetStore>();

	Logger::Log("Game constructor called!");
}

Game::~Game()
{
	Logger::Log("Game destructor called!");
}

void Game::initialize()
{
	//setup();
	// is_running_ = true;

	raylib::InitWindow(window_width_, window_height_, "EverGreen Engine"); //Creates Window Object

	SetTargetFPS(30); //Runs at 30 FPS
}

void Game::run()
{
	using Clock = std::chrono::steady_clock;

	// Convert your existing target frame duration into the clock's
	// native duration type.
	const Clock::duration target_frame_time =
		std::chrono::duration_cast<Clock::duration>(
			std::chrono::duration<double>(kSecondsPerFrame)
		);

	// Give the first frame a normal delta time instead of nearly zero.
	auto previous_frame_start =
		Clock::now() - target_frame_time;

	while (!raylib::WindowShouldClose())
	{
		const auto frame_start = Clock::now();

		// Calculate the duration from one frame start to the next.
		const float delta_seconds =
			std::chrono::duration<float>(
				frame_start - previous_frame_start
			).count();

		previous_frame_start = frame_start;




		// Keep sf::Time because your update functions and ImGui use it.
		//elapse_time_ = sf::seconds(delta_seconds);

		// processInput();
		update(elapse_time_);
		render();

		// Sleep only for the remaining part of the frame.
		// If the frame took longer than the target, this returns immediately.
		std::this_thread::sleep_until(
			frame_start + target_frame_time
		);
	}
}

void Game::processInput()
{
	while (const std::optional event = window.pollEvent())
	{
		ImGui::SFML::ProcessEvent(window, *event);

		if (event->is<sf::Event::Closed>())
		{
			window.close();
			is_running_ = false;
		}

		if (const auto key_event = event->getIf<sf::Event::KeyPressed>())
		{
			event_bus_->emitEvent<KeyPressedEvent>(key_event->code);

		}
	}

}

sf::Vector2f playerPosition(0, 0);
sf::Vector2f playerVelocity(0, 0);

void Game::setup()
{
	lua_.open_libraries(sol::lib::base, sol::lib::math);

	current_level_ = "Assets/Scripts/level_full.lua";
	loadLevel();
}

// Builds a fresh registry with every system, then fills it from the current
// level file. Used for the first load and for every reset: throwing the whole
// registry away is what guarantees nothing from the previous run survives.
void Game::loadLevel()
{
	registry_ = std::make_unique<Registry>();

	// registry_->addSystem<MovementSystem>();
	// registry_->addSystem<RenderSpriteSystem>();
	// registry_->addSystem<RenderShapeSystem>();
	// registry_->addSystem<ColliderSystem>();
	// registry_->addSystem<DamageSystem>();
	// registry_->addSystem<KeyboardControlSystem>();
	// registry_->addSystem<AnimationSystem>();
	// registry_->addSystem<RenderGUISystem>();
	// registry_->addSystem<ProjectileEmitSystem>();
	// registry_->addSystem<ProjectileLifecycleSystem>();
	// registry_->addSystem<CameraMovementSystem>();
	// registry_->addSystem<RenderColliderSystem>();
	// registry_->addSystem<RenderTextSystem>();
	// registry_->addSystem<RenderHealthBarSystem>();

	LevelLoader::load(lua_, registry_, asset_store_, *this, current_level_);

	camera.position = { 0, 0 };
}

void Game::update(sf::Time elapse_time)
{
	// Reset all event handlers for the current frame
	event_bus_->reset();

	// Handled here, after the event handlers were dropped and before anything
	// touches the registry, so no system is running when the old one is freed
	if (level_reset_requested_)
	{
		level_reset_requested_ = false;
		Logger::Log("Resetting level " + current_level_);
		loadLevel();
	}

	// Perform the subscription of the events for all systems
	// registry_->getSystem<DamageSystem>().subscribeToEvents(event_bus_);
	// registry_->getSystem<KeyboardControlSystem>().subscribeToEvents(event_bus_);
	// registry_->getSystem<ProjectileEmitSystem>().subscribeToEvents(event_bus_);

	// Update the registry to process the entities that are waiting to be created/deleted
	registry_->update();

	// Invoke all the systems that need to update
	// registry_->getSystem<MovementSystem>().update(elapse_time.asSeconds(), gravity);
	// registry_->getSystem<ColliderSystem>().update(event_bus_);
	// registry_->getSystem<AnimationSystem>().update();
	// registry_->getSystem<ProjectileEmitSystem>().update(elapse_time.asSeconds(), registry_);
	// registry_->getSystem<ProjectileLifecycleSystem>().update(elapse_time.asSeconds());
	// registry_->getSystem<CameraMovementSystem>().update(camera, *this);

	// ImGui::SFML::Update(window_, elapse_time);
}
void Game::render()
{


	//Invoke all systems that need to render
	// Sprites first so the tilemap and artwork sit behind the primitives
	// registry_->getSystem<RenderSpriteSystem>().update(&window_, asset_store_, camera);
	// registry_->getSystem<RenderShapeSystem>().update(&window_, camera);
	// if (show_colliders)
	// {
	// 	registry_->getSystem<RenderColliderSystem>().update(&window_, camera);
	// }
	// registry_->getSystem<RenderTextSystem>().update(&window_, asset_store_);
	// registry_->getSystem<RenderHealthBarSystem>().update(&window_, asset_store_, camera);
	//
	// // The editor draws last so entities never paint over its panel
	// registry_->getSystem<RenderGUISystem>().update(window_, *this);
	BeginDrawing();

	ClearBackground(raylib.Color(147, 211, 196, 255));

	Raylib::DrawText("Congrats! You created your first window!", 190, 200, 20, BLACK);

	EndDrawing();

	window.display();
}

void Game::destroy()
{
	// ImGui::SFML::Shutdown();
	CloseWindow();
}