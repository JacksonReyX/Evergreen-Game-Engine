#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#import "raylib.h"
#include "raylib-cpp.hpp"

class AssetStore {
private:
    std::map<std::string, raylib::Texture2D> textures_;
    std::map<std::string, sf::Font> fonts_;
    // TODO: create a map for audio

public:
    AssetStore();
    ~AssetStore();

    void clearAssets();
    void addTexture(const std::string& asset_id, const std::string& file_path);
    void addFont(const std::string& asset_id, const std::string& file_path);
    raylib::Texture2D* getTexture(const std::string& asset_id);
    sf::Font& getFont(const std::string& asset_id);
};