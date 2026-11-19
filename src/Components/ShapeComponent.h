#pragma once

#include <SFML/Graphics.hpp>

enum class ShapeType
{
	rectangle,
	circle
};

////////////////////////////////////////////////////////////////////////////////
// ShapeComponent
////////////////////////////////////////////////////////////////////////////////
// A primitive drawn straight from geometry and a solid color. It carries no
// texture: anything that needs an image uses a SpriteComponent instead, and an
// entity is free to hold both.
//
// size_     : width / height in world units, before the transform scale.
//             For a circle, size_.x is the diameter.
// is_fixed_ : true for UI/HUD shapes that ignore the camera.
////////////////////////////////////////////////////////////////////////////////
struct ShapeComponent
{
	sf::Vector2f size_;
	ShapeType type_;
	sf::Color color_;
	bool visible_;
	bool is_fixed_;

	ShapeComponent(
		sf::Vector2f size = sf::Vector2f(0.f, 0.f),
		ShapeType type = ShapeType::rectangle,
		sf::Color color = sf::Color::White,
		bool is_fixed = false
	)
		: size_(size),
		  type_(type),
		  color_(color),
		  visible_(true),
		  is_fixed_(is_fixed)
	{
	}
};
