#pragma once

#include <string>
#include <SFML/Graphics.hpp>

////////////////////////////////////////////////////////////////////////////////
// SpriteComponent
////////////////////////////////////////////////////////////////////////////////
// Everything needed to draw a textured quad from the asset store.
//
// size_         : destination size, in world units, before the transform scale.
// src_size_     : size of the source rectangle inside the texture (frame size).
// src_position_ : top-left corner of the source rectangle inside the texture.
// is_fixed_     : true for UI/HUD sprites that ignore the camera.
////////////////////////////////////////////////////////////////////////////////
struct SpriteComponent
{
	std::string asset_id_;
	raylib::Vector2 size_;
	raylib::Vector2 src_size_;
	raylib::Vector2 src_position_;
	raylib::Color tint_;
	bool visible_;
	bool is_fixed_;

	SpriteComponent(
		std::string asset_id = "",
		raylib::Vector2 size = raylib::Vector2(0.f, 0.f),
		raylib::Vector2 src_size = raylib::Vector2(0, 0),
		raylib::Vector2 src_position = raylib::Vector2(0, 0),
		bool is_fixed = false,
		raylib::Color tint = raylib::Color(WHITE)
	)
		: asset_id_(asset_id),
		  size_(size),
		  src_size_(src_size),
		  src_position_(src_position),
		  tint_(tint),
		  visible_(true),
		  is_fixed_(is_fixed)
	{
	}
};
