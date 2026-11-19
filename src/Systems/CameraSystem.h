#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Components/MoveableComponent.h"
#include "../Components/TransformComponent.h"
#import "raylib.h"
#include "raylib-cpp.hpp"

class CameraSystem : public System {
    public:
        CameraSystem() {
            requiredComponent<TransformComponent>();
            requiredComponent<MoveableComponent>();
        }

    void followPlayerUpdate(raylib::Camera2D* camera) {
            //camera->SetOffset(raylib::Vector2(200,300));
          for (auto entity : getSystemEntities() ) {
              if (entity.hasTag("player")) {
                  camera->SetTarget(entity.getComponent<TransformComponent>().position_ - (entity.getComponent<TransformComponent>().size_ * camera->GetZoom()) / 2 );
                  break;
              }
          }
        }
    void testCameraZoom(raylib::Camera2D* camera) {
            int currentZoom = camera->GetZoom();
            if (IsKeyPressed(KEY_P)) {
                currentZoom++;
                Logger::Log("Current zoom: " + std::to_string(currentZoom));
            }
            if (IsKeyPressed(KEY_L)) {
                currentZoom--;
                Logger::Log("Current zoom: " + std::to_string(currentZoom));
            }

            camera->SetOffset({(1200 - static_cast<float>(currentZoom)) / 2.0f, (800 - static_cast<float>(currentZoom)) / 2.0f});
            camera->SetZoom(currentZoom);




        }
};
