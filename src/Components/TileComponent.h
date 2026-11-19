//
// Created by Jackson Reynolds on 10/11/26.
//

#ifndef EVERGREEN_ENGINE_TILECOMPONENT_H
#define EVERGREEN_ENGINE_TILECOMPONENT_H

#endif //EVERGREEN_ENGINE_TILECOMPONENT_H

#include <string>
struct TileComponent {
    std::string mapFilePath;
    std::string mapTexturePath;

    TileComponent(std::string mapFilePath = "", std::string mapTexturePath = "") :
        mapFilePath(mapFilePath),
        mapTexturePath(mapTexturePath) {}

};