#pragma once

#include <SFML/Graphics.hpp>

struct TextLabelComponent
{
	sf::Vector2f position_;
	std::string text_;
	std::string asset_id_;
	sf::Color color_;
	int size_;
	bool is_fixed_;

	TextLabelComponent(
		sf::Vector2f position = sf::Vector2f(0.f, 0.f),
		const std::string& text = "",
		const std::string& asset_id = "",
		const sf::Color& color = { 0, 0, 0 },
		const int size = 24,
		bool is_fixed = true
	)
		: position_(position),
		  text_(text),
		  asset_id_(asset_id),
		  color_(color),
		  size_(size),
		  is_fixed_(is_fixed)
	{
	}
};