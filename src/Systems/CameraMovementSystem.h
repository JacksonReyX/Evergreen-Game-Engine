#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Game/game.h"
#include "../Components/TransformComponent.h"
#include "../Components/CameraFollowComponent.h"

class CameraMovementSystem : public System
{
public:
	CameraMovementSystem()
	{
		requiredComponent<CameraFollowComponent>();
		requiredComponent<TransformComponent>();
	}

	void update(sf::IntRect& camera, Game& game)
	{
		// Loop all entities that the system is interested in
		for (auto entity : getSystemEntities())
		{
			auto& transform = entity.getComponent<TransformComponent>();
			
			if (transform.position_.x + (camera.size.x / 2) < game.map_width_) {
				camera.position.x = transform.position_.x - (camera.size.x / 2);
			}

			if (transform.position_.y + (camera.size.y / 2) < game.map_height_) {
				camera.position.y = transform.position_.y - (camera.size.y / 2);
			}

			camera.position.x = camera.position.x < 0 ? 0 : camera.position.x;
			camera.position.y = camera.position.y < 0 ? 0 : camera.position.y;

			camera.position.x = camera.position.x > camera.size.x ? camera.size.x : camera.position.x;
			camera.position.y = camera.position.y > camera.size.y ? camera.size.y : camera.position.y;
		}
	}
};