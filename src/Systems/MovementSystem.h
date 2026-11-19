#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Game/game.h"
#include "../Components/TransformComponent.h"
#include "../Components/RigidBodyComponent.h"

class MovementSystem : public System
{
public:
	MovementSystem()
	{
		requiredComponent<TransformComponent>();
		requiredComponent<RigidBodyComponent>();
	}

	void update()
	{
		// Loop all entities that the system is interested in
		for (auto entity: getSystemEntities())
		{
			// Update entity position based on its velocity
			auto& transform = entity.getComponent<TransformComponent>();
			auto& rigidbody = entity.getComponent<RigidBodyComponent>();

			if (!rigidbody.is_static_) {

				if (gravity) {
					rigidbody.velocity_.y += kGravity * delta_time;
				}

				transform.position_.x += rigidbody.velocity_.x * delta_time;
				transform.position_.y += rigidbody.velocity_.y * delta_time;

				//Logger::Log("Entity id = " + std::to_string(entity.getId()) + " position now is ( " + std::to_string(transform.position_.x) + " , " + std::to_string(transform.position_.y) + " )");

			}
		}
	}
};