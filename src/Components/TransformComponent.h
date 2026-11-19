#pragma once

#include <SFML/Graphics.hpp>

struct TransformComponent
{
	raylib::Vector2 position_;
	raylib::Vector2 scale_;
	raylib::Vector2 size_;
	float rotation_;

	TransformComponent(
		raylib::Vector2 position = raylib::Vector2(0.f, 0.f),
		raylib::Vector2 size = raylib::Vector2(1.f, 1.f),
		raylib::Vector2 scale = raylib::Vector2(1.f, 1.f),
		float rotation = 0.f
	)
		: position_(position),
		  scale_(scale),
		  rotation_(rotation),
	      size_(size)
	{
	}
};