#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Components/ShapeComponent.h"
#include "../Components/TransformComponent.h"

#include <SFML/Graphics.hpp>

class RenderShapeSystem : public System
{
public:
	RenderShapeSystem()
	{
		requiredComponent<TransformComponent>();
		requiredComponent<ShapeComponent>();
	}

	void update(sf::RenderWindow* window, sf::IntRect& camera)
	{
		for (auto entity : getSystemEntities())
		{
			const auto transform = entity.getComponent<TransformComponent>();
			const auto shape = entity.getComponent<ShapeComponent>();

			if (!shape.visible_)
			{
				continue;
			}

			const sf::Vector2f position = {
				transform.position_.x - (shape.is_fixed_ ? 0 : camera.position.x),
				transform.position_.y - (shape.is_fixed_ ? 0 : camera.position.y)
			};

			switch (shape.type_)
			{
			case ShapeType::rectangle:
			{
				sf::RectangleShape rect(shape.size_.componentWiseMul(transform.scale_));
				rect.setPosition(position);
				rect.setFillColor(shape.color_);
				rect.setRotation(sf::degrees(transform.rotation_));

				window->draw(rect);
				break;
			}
			case ShapeType::circle:
			{
				sf::CircleShape circle((shape.size_.x / 2) * transform.scale_.x);
				circle.setPosition(position);
				circle.setFillColor(shape.color_);
				circle.setRotation(sf::degrees(transform.rotation_));

				window->draw(circle);
				break;
			}
			}
		}
	}
};
