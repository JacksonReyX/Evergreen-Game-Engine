#pragma once

#include <SFML/Graphics.hpp>

struct ProjectileEmitterComponent
{
	sf::Vector2f position_;
	sf::Vector2f scale_;
	float rotation_;

	sf::Vector2f projectile_velocity_;
	int repeat_frequency_;
	int projectile_duration_;
	int hit_percent_damage_;
	bool is_friendly_;
	float elapsed_since_last_emission_;
	bool emit_immediately;

	ProjectileEmitterComponent(
		sf::Vector2f projectile_velocity = sf::Vector2f(0.f, 0.f),
		int repeat_frequency = 0,
		int projectile_duration = 10,
		int hit_percent_damage = 10,
		bool is_friendly = false,
		float elapsed_since_last_emission = 0,
		bool emit_immediately = false
	)
		: projectile_velocity_(projectile_velocity),
		repeat_frequency_(repeat_frequency),
		projectile_duration_(projectile_duration),
		hit_percent_damage_(hit_percent_damage),
		is_friendly_(is_friendly),
		elapsed_since_last_emission_(
			emit_immediately ? repeat_frequency : 0.0f
		)
	{
	}
};