#include "AssetStore.h"

#include "Texture.hpp"
#include "../Logger/Logger.h"


AssetStore::AssetStore() {
    Logger::Log("AssetStore constructor called!");
}

AssetStore::~AssetStore() {
    clearAssets();
    Logger::Log("AssetStore destructor called!");
}

void AssetStore::clearAssets() {
    textures_.clear();
}

void AssetStore::addTexture(const std::string& asset_id, const std::string& filePath) {
    // Add the texture to the map
    // emplace takes the values and passes them into the constructor and stores the value inside the containers memory
    // this removes the need to make a temporary object and waste memory
    textures_.emplace(asset_id, LoadTexture(filePath.c_str()));
    Logger::Log("New raylib texture added to the Asset Store with id = " + asset_id);
}

raylib::Texture2D* AssetStore::getTexture(const std::string & assetId) {
    return &textures_[assetId];
}

void AssetStore::addFont(const std::string& asset_id, const std::string& file_path) {
    sf::Font font(file_path.c_str());
    fonts_.emplace(asset_id, font);
}

sf::Font& AssetStore::getFont(const std::string& asset_id) {
    return fonts_[asset_id];
}
