#pragma once

#include <SFML/Graphics.hpp>

struct KeyboardControlledComponent
{
	sf::Vector2f upVelocity_;
	sf::Vector2f rightVelocity_;
	sf::Vector2f downVelocity_;
	sf::Vector2f leftVelocity_;

	// Last direction an arrow key pointed, one of (0,-1) (1,0) (0,1) (-1,0).
	// Lets a stationary entity still know which way it is aiming.
	sf::Vector2f facing_;

	KeyboardControlledComponent(sf::Vector2f upVelocity = sf::Vector2f(0.f, 0.f), sf::Vector2f rightVelocity = sf::Vector2f(0.f, 0.f), sf::Vector2f downVelocity = sf::Vector2f(0.f, 0.f), sf::Vector2f leftVelocity = sf::Vector2f(0.f, 0.f))
		: upVelocity_(upVelocity),
		rightVelocity_(rightVelocity),
		downVelocity_(downVelocity),
		leftVelocity_(leftVelocity),
		facing_(0.f, -1.f)
	{

	}
};