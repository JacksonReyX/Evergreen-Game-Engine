#pragma once


struct HealthComponent
{
	int health_percentage_;

	HealthComponent(
		float health_percentage = 0.f
	)
		: health_percentage_(health_percentage)
	{
	}
};