#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Components/TransformComponent.h"
#include "../Components/BoxColliderComponent.h"

#include <SFML/Graphics.hpp>


class RenderColliderSystem : public System
{
public:
	RenderColliderSystem()
	{
		requiredComponent<TransformComponent>();
		requiredComponent<BoxColliderComponent>();
	}

	void update(sf::RenderWindow* window, sf::IntRect& camera) {
		for (auto entity : getSystemEntities()) {
			const auto transform = entity.getComponent<TransformComponent>();
			const auto collider = entity.getComponent<BoxColliderComponent>();

			sf::RectangleShape rect(collider.size_.componentWiseMul(transform.scale_));
			rect.setPosition({ transform.position_.x - camera.position.x,  transform.position_.y - camera.position.y });
			rect.setOutlineColor(sf::Color::Green);
			rect.setOutlineThickness(2);
			rect.setFillColor(sf::Color::Transparent);

			window->draw(rect);
		}
	}
};