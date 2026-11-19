#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Components/TransformComponent.h"
#include "../Components/RigidBodyComponent.h"
#include "../Components/BoxColliderComponent.h"
#include "../Events/CollisionEvent.h"

class ColliderSystem : public System
{
public:
	ColliderSystem()
	{
		requiredComponent<TransformComponent>();
		requiredComponent<BoxColliderComponent>();
		requiredComponent<RigidBodyComponent>();
	}

	void update(std::unique_ptr<EventBus>& event_bus)
	{
		// Loop all entities that the system is interested in
		for (auto a : getSystemEntities())
		{
			auto& a_transform = a.getComponent<TransformComponent>();
			auto a_collider = a.getComponent<BoxColliderComponent>();
			auto& a_rigidbody = a.getComponent<RigidBodyComponent>();

			for (auto b : getSystemEntities())
			{
				auto& b_transform = b.getComponent<TransformComponent>();
				auto b_collider = b.getComponent<BoxColliderComponent>();
				auto& b_rigidbody = b.getComponent<RigidBodyComponent>();

				if (a == b)
				{
					continue;
				}

				// Test the boxes at the size they are drawn by the collider
				// debug view: the collider size times the transform scale.
				// Without the scale, a scaled-up entity would look bigger
				// than the box it actually collides with.
				const sf::Vector2f a_size = a_collider.size_.componentWiseMul(a_transform.scale_);
				const sf::Vector2f b_size = b_collider.size_.componentWiseMul(b_transform.scale_);

				bool collision_detected = checkAABBCollision(a_transform.position_, a_size, b_transform.position_, b_size);

				if (collision_detected)
				{
					Logger::Log("Collision detected between -> entity " + std::to_string(a.getId()) + "  and entity " + std::to_string(b.getId()));

					//// compute centers once
					//sf::Vector2f a_center = { a_transform.position_.x + 0.5f * a_collider.size_.x,
					//						  a_transform.position_.y + 0.5f * a_collider.size_.y };
					//sf::Vector2f b_center = { b_transform.position_.x + 0.5f * b_collider.size_.x,
					//						  b_transform.position_.y + 0.5f * b_collider.size_.y };

					//// overlaps (positive if intersecting)
					//sf::Vector2f overlap = getAABBOverlap(a_transform.position_, a_collider.size_,
					//	b_transform.position_, b_collider.size_);
					//if (overlap.x <= 0.0f || overlap.y <= 0.0f) continue; // safety

					//// choose least-penetration axis and build normal from A->B using CENTER delta
					//sf::Vector2f d = { b_center.x - a_center.x, b_center.y - a_center.y };

					//float penetration;
					//sf::Vector2f normal;

					//if (overlap.x < overlap.y) {
					//	penetration = overlap.x;
					//	normal = { (d.x >= 0.0f ? 1.0f : -1.0f), 0.0f };
					//}
					//else {
					//	penetration = overlap.y;
					//	normal = { 0.0f, (d.y >= 0.0f ? 1.0f : -1.0f) };
					//}

					//// 1) velocity response along normal
					//resolveCollision(a_rigidbody, b_rigidbody, normal);

					//// 2) positional correction using penetration
					//positionalCorrection(a_transform.position_, a_rigidbody.inv_mass_,
					//	b_transform.position_, b_rigidbody.inv_mass_,
					//	normal, penetration);

					event_bus->emitEvent<CollisionEvent>(a, b);
				}
			}
		}
	}

	bool checkAABBCollision(sf::Vector2f a_pos, sf::Vector2f a_size, sf::Vector2f b_pos, sf::Vector2f b_size)
	{
		return (
			a_pos.x < b_pos.x + b_size.x &&
			b_pos.x < a_pos.x + a_size.x &&
			a_pos.y < b_pos.y + b_size.y &&
			b_pos.y < a_pos.y + a_size.y 
			);
	}

	sf::Vector2f getAABBOverlap(sf::Vector2f a_pos, sf::Vector2f a_size,
		sf::Vector2f b_pos, sf::Vector2f b_size)
	{
		// centers from min+size
		sf::Vector2f a_center = { a_pos.x + 0.5f * a_size.x, a_pos.y + 0.5f * a_size.y };
		sf::Vector2f b_center = { b_pos.x + 0.5f * b_size.x, b_pos.y + 0.5f * b_size.y };

		sf::Vector2f d = { b_center.x - a_center.x, b_center.y - a_center.y }; // center delta

		// half extents
		sf::Vector2f a_half = { 0.5f * a_size.x, 0.5f * a_size.y };
		sf::Vector2f b_half = { 0.5f * b_size.x, 0.5f * b_size.y };

		// positive overlaps (if any)
		float ox = (a_half.x + b_half.x) - std::fabs(d.x);
		float oy = (a_half.y + b_half.y) - std::fabs(d.y);

		return { ox, oy }; 
	}


	void resolveCollision(RigidBodyComponent& a, RigidBodyComponent& b, sf::Vector2f normal)
	{
		normal = normal.normalized();

		float u1 = a.velocity_.dot(normal);
		float u2 = b.velocity_.dot(normal);

		if (u2 - u1 > 0.0f) return;

		float e = fmin(a.e_, b.e_);

		float v1n = u1, v2n = u2;

		if (!a.is_static_ && !b.is_static_) {
			float m1 = a.mass_;
			float m2 = b.mass_;
			float denom = (m1 + m2);
			if (denom == 0.0f) return;

			// CORRECT 1-D two-body update (note m1 - e*m2 and m2 - e*m1)
			v1n = ((m1 - e * m2) * u1 + (1.0f + e) * m2 * u2) / denom;
			v2n = ((m2 - e * m1) * u2 + (1.0f + e) * m1 * u1) / denom;
		}
		else if (a.is_static_ && !b.is_static_) {
			v2n = -e * u2; // bounce against static object
		}
		else if (!a.is_static_ && b.is_static_) {
			v1n = -e * u1;
		}
		else {
			return;
		}

		// Replace only the normal component, keep tangent velocity the same
		a.velocity_ += (v1n - u1) * normal;
		b.velocity_ += (v2n - u2) * normal;
	}

	void positionalCorrection(sf::Vector2f& posA, float invMA,
		sf::Vector2f& posB, float invMB,
		const sf::Vector2f& normal, float penetration)
	{
		const float beta = 0.2f;   // fraction per iteration (tune 0.1�0.3)
		const float slop = 0.01f;  // tolerance (match your world units)

		float denom = invMA + invMB;
		if (denom == 0.0f) return;

		float corrMag = beta * std::max(penetration - slop, 0.0f) / denom;
		sf::Vector2f corr = { corrMag * normal.x, corrMag * normal.y };

		posA.x -= invMA * corr.x; posA.y -= invMA * corr.y;
		posB.x += invMB * corr.x; posB.y += invMB * corr.y;
	}
};