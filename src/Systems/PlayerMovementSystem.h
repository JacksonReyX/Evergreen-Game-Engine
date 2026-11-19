//
// Created by Jackson Reynolds on 10/21/26.
//
#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Components/SpriteComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/MoveableComponent.h"
#include "../Events/KeyPressedEvent.h"
#include "../EventBus/EventBus.h"
#import "raylib.h"
#include "raylib-cpp.hpp"

class PlayerMovementSystem : public System {
    public:
        PlayerMovementSystem() {
            requiredComponent<TransformComponent>();
            requiredComponent<MoveableComponent>();

        }

    void subscribeToEvents(std::unique_ptr<EventBus>& event_bus) {
            event_bus->subscribeToEvent<KeyPressedEvent>(this, &PlayerMovementSystem::movePlayer);
        }

    void movePlayer(KeyPressedEvent& event) {
            for (auto entity : getSystemEntities()) {
                if (entity.hasTag("player")) {
                    entity.getComponent<MoveableComponent>().player_moving_ = false;

                    if (IsKeyDown(KEY_D)) {entity.getComponent<MoveableComponent>().player_moving_ = true; entity.getComponent<MoveableComponent>().right_ = true; entity.getComponent<MoveableComponent>().direction_ = 3;}
                    if (IsKeyDown(KEY_A)) {entity.getComponent<MoveableComponent>().player_moving_ = true; entity.getComponent<MoveableComponent>().left_ = true; entity.getComponent<MoveableComponent>().direction_ = 2;}
                    if (IsKeyDown(KEY_W)) {entity.getComponent<MoveableComponent>().player_moving_ = true; entity.getComponent<MoveableComponent>().up_ = true; entity.getComponent<MoveableComponent>().direction_ = 1;}
                    if (IsKeyDown(KEY_S)) {entity.getComponent<MoveableComponent>().player_moving_ = true; entity.getComponent<MoveableComponent>().down_ = true; entity.getComponent<MoveableComponent>().direction_ = 0;}

                    if (entity.getComponent<MoveableComponent>().player_moving_ == true) {
                            if (entity.getComponent<MoveableComponent>().right_) {
                                entity.getComponent<TransformComponent>().position_.x = entity.getComponent<TransformComponent>().position_.x + entity.getComponent<MoveableComponent>().speed_ * GetFrameTime();
                                entity.getComponent<MoveableComponent>().right_ = false;
                            }
                            if (entity.getComponent<MoveableComponent>().left_) {
                                entity.getComponent<TransformComponent>().position_.x = entity.getComponent<TransformComponent>().position_.x - entity.getComponent<MoveableComponent>().speed_ * GetFrameTime();
                                entity.getComponent<MoveableComponent>().left_ = false;
                            }
                            if (entity.getComponent<MoveableComponent>().up_) {
                                entity.getComponent<TransformComponent>().position_.y = entity.getComponent<TransformComponent>().position_.y - entity.getComponent<MoveableComponent>().speed_ * GetFrameTime();
                                entity.getComponent<MoveableComponent>().up_ = false;
                            }
                            if (entity.getComponent<MoveableComponent>().down_) {
                                entity.getComponent<TransformComponent>().position_.y = entity.getComponent<TransformComponent>().position_.y + entity.getComponent<MoveableComponent>().speed_ * GetFrameTime();
                                entity.getComponent<MoveableComponent>().down_ = false;
                            }
                    }
                    break;
                }
            }
        }
};
