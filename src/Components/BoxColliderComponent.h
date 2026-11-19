#pragma once
#include <SFML/Graphics.hpp>

struct BoxColliderComponent
{
	raylib::Vector2 offset_;
	raylib::Vector2 size_;

	BoxColliderComponent(
		raylib::Vector2 size = raylib::Vector2(0, 0),
		raylib::Vector2 offset = raylib::Vector2(0,0)
	)
		: size_(size), offset_(offset)
	{
	}
};