#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Components/SpriteComponent.h"
#include "../Components/ShapeComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/HealthComponent.h"

#include <SFML/Graphics.hpp>
#include "../AssetStore/AssetStore.h"

class RenderHealthBarSystem : public System
{
public:
    RenderHealthBarSystem()
	{
		requiredComponent<TransformComponent>();
		requiredComponent<HealthComponent>();
	}

	void update(sf::RenderWindow* window, std::unique_ptr<AssetStore>& assetStore, sf::IntRect& camera)
	{
		for (auto entity : getSystemEntities())
		{
            const auto transform = entity.getComponent<TransformComponent>();
            const auto health = entity.getComponent<HealthComponent>();

            // Draw a the health bar with the correct color for the percentage
            sf::Color healthBarColor = { 255, 255, 255 };

            if (health.health_percentage_ >= 0 && health.health_percentage_ < 40) {
                // 0-40 = red
                healthBarColor = { 255, 0, 0 };
            }
            if (health.health_percentage_ >= 40 && health.health_percentage_ < 80) {
                // 40-80 = yellow
                healthBarColor = { 255, 255, 0 };
            }
            if (health.health_percentage_ >= 80 && health.health_percentage_ <= 100) {
                // 80-100 = green
                healthBarColor = { 0, 255, 0 };
            }

            // Width of the entity as it is drawn, so the bar lands on its right edge
            float entity_width = 0.f;

            if (entity.hasComponent<SpriteComponent>()) {
                const auto& sprite = entity.getComponent<SpriteComponent>();
                entity_width = sprite.size_.x > 0.f
                    ? sprite.size_.x
                    : static_cast<float>(sprite.src_size_.x);
            }
            else if (entity.hasComponent<ShapeComponent>()) {
                entity_width = entity.getComponent<ShapeComponent>().size_.x;
            }

            // Position the health bar indicator in the top-right part of the entity
            int healthBarWidth = 15;
            int healthBarHeight = 3;
            double healthBarPosX = (transform.position_.x + (entity_width * transform.scale_.x)) - camera.position.x;
            double healthBarPosY = (transform.position_.y) - camera.position.y;

            sf::RectangleShape healthBarRectangle(sf::Vector2f(healthBarWidth * (health.health_percentage_ / 100.0), healthBarHeight));
            healthBarRectangle.setPosition(sf::Vector2f(healthBarPosX, healthBarPosY));
            healthBarRectangle.setFillColor(healthBarColor);

            window->draw(healthBarRectangle);

            // Render the health percentage text label indicator
            std::string healthText = std::to_string(health.health_percentage_);

            sf::Text text(assetStore->getFont("pico8-font-5")); // a font is required to make a text object

            text.setString(healthText);
            text.setCharacterSize(5); // in pixels, not points!
            text.setFillColor(healthBarColor);
            text.setPosition(sf::Vector2f(healthBarPosX, healthBarPosY + 5));

            window->draw(text);
		}
	}
};
