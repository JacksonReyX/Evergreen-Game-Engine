#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Components/KeyboardControlledComponent.h"
#include "../Components/RigidBodyComponent.h"
#include "../Components/SpriteComponent.h"
#include "../EventBus/EventBus.h"
#include "../Events/KeyPressedEvent.h"

class KeyboardControlSystem : public System {
public:
    KeyboardControlSystem() {
        requiredComponent<KeyboardControlledComponent>();
        requiredComponent<RigidBodyComponent>();
    }

    void subscribeToEvents(std::unique_ptr<EventBus>& event_bus) {
        event_bus->subscribeToEvent<KeyPressedEvent>(this, &KeyboardControlSystem::onKeyPressed);
    }

    void onKeyPressed(KeyPressedEvent& event) {
    
        sf::Keyboard::Scancode key_code = sf::Keyboard::delocalize(event.pressed_key_);
        std::string key_pressed = sf::Keyboard::getDescription(key_code);

        Logger::Log("Key pressed event emitted: [ " + std::to_string((int)key_code) + " ] " + key_pressed);

        for (auto entity : getSystemEntities())
        {
            auto& keyboard_control = entity.getComponent<KeyboardControlledComponent>();
            auto& rigidbody = entity.getComponent<RigidBodyComponent>();

            const bool has_sprite = entity.hasComponent<SpriteComponent>();

            sf::Keyboard::Scancode key_code = sf::Keyboard::delocalize(event.pressed_key_);

            // Row of the sprite sheet matching the facing direction
            int facing_row = -1;

            switch (key_code)
            {
            case sf::Keyboard::Scancode::Up:
                rigidbody.velocity_ = keyboard_control.upVelocity_;
                keyboard_control.facing_ = { 0.f, -1.f };
                facing_row = 0;
                break;
            case sf::Keyboard::Scancode::Right:
                rigidbody.velocity_ = keyboard_control.rightVelocity_;
                keyboard_control.facing_ = { 1.f, 0.f };
                facing_row = 1;
                break;
            case sf::Keyboard::Scancode::Down:
                rigidbody.velocity_ = keyboard_control.downVelocity_;
                keyboard_control.facing_ = { 0.f, 1.f };
                facing_row = 2;
                break;
            case sf::Keyboard::Scancode::Left:
                rigidbody.velocity_ = keyboard_control.leftVelocity_;
                keyboard_control.facing_ = { -1.f, 0.f };
                facing_row = 3;
                break;

            default:
                break;
            }

            if (has_sprite && facing_row >= 0)
            {
                auto& sprite = entity.getComponent<SpriteComponent>();
                sprite.src_position_.y = sprite.src_size_.y * facing_row;
            }
        }
    }

    void Update() {
        // TODO:...
    }
};
