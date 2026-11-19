#pragma once

#include <SFML/Graphics.hpp>

struct RigidBodyComponent
{
	sf::Vector2f velocity_;
	bool is_static_;
	float e_; // bounciness
	float mass_;
	float inv_mass_;

	RigidBodyComponent(sf::Vector2f velocity = sf::Vector2f(0.f, 0.f), bool is_static = false, float mass = 1, float e = 0)
		: velocity_(velocity),
		  is_static_(is_static),
		  e_(e),
		  mass_(mass)
	{
		if (is_static_)
		{
			mass_ = 0;
			inv_mass_ = 0;
		}
		
		if (mass_ > 0)
		{
			inv_mass_ = (1 / mass_);
		}
	}
};