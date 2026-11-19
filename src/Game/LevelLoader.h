#pragma once

#include <string>

#include "game.h"
#include "../ECS/ECS.h"
#include "../AssetStore/AssetStore.h"

#include <sol.hpp>

class LevelLoader
{

public:
	
	LevelLoader();
	~LevelLoader();

	static void load(sol::state& lua, std::unique_ptr<Registry>& registry, std::unique_ptr<AssetStore>& asset_store, Game& game, const std::string& config_file);
	static void createEntity(Game& game, Entity& entity, const std::string& type, float x, float y, float sx, float sy, int r, int g, int b, float w, float h);
};

