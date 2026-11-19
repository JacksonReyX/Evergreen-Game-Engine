#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Game/game.h"
#include "../Components/TransformComponent.h"
#include "../Components/RigidBodyComponent.h"
#include "../Components/ProjectileEmitterComponent.h"
#include "../Components/SpriteComponent.h"
#include "../Components/ShapeComponent.h"
#include "../Components/BoxColliderComponent.h"
#include "../Components/ProjectileComponent.h"
#include "../Components/KeyboardControlledComponent.h"
#include "../EventBus/EventBus.h"
#include "../Events/KeyPressedEvent.h"

class ProjectileEmitSystem : public System
{
public:
	ProjectileEmitSystem()
	{
		requiredComponent<ProjectileEmitterComponent>();
		requiredComponent<TransformComponent>();
	}

    void subscribeToEvents(std::unique_ptr<EventBus>& event_bus) {
        event_bus->subscribeToEvent<KeyPressedEvent>(this, &ProjectileEmitSystem::onKeyPressed);
    }

    // Size of the emitter as it is drawn, whether it is a sprite or a shape.
    // Used to start the projectile in the middle of the emitter instead of on
    // its top-left corner.
    static sf::Vector2f getVisualSize(Entity entity) {

        if (entity.hasComponent<SpriteComponent>()) {
            const auto& sprite = entity.getComponent<SpriteComponent>();
            return {
                sprite.size_.x > 0.f ? sprite.size_.x : static_cast<float>(sprite.src_size_.x),
                sprite.size_.y > 0.f ? sprite.size_.y : static_cast<float>(sprite.src_size_.y)
            };
        }

        if (entity.hasComponent<ShapeComponent>()) {
            return entity.getComponent<ShapeComponent>().size_;
        }

        return { 0.f, 0.f };
    }

    // Every projectile is a 4x4 quad
    static constexpr float kProjectileSize = 4.f;

    // Gap left between the shooter's collider and a new projectile
    static constexpr float kSpawnMargin = 2.f;

    static float sign(float value) {
        return static_cast<float>((value > 0.f) - (value < 0.f));
    }

    // Where a projectile starts: just outside the shooter's collider, on the
    // side it is flying towards. Spawning in the middle of the shooter made
    // the projectile overlap it on its first frame, so a non-friendly shot
    // from the player hit the player the instant it was fired.
    //
    // direction is per axis: -1, 0 or +1.
    static sf::Vector2f spawnPosition(Entity shooter, const sf::Vector2f& direction) {

        const auto& transform = shooter.getComponent<TransformComponent>();

        // Use the collider when there is one, since that is the box
        // collisions test against; otherwise fall back to what is drawn
        sf::Vector2f footprint = shooter.hasComponent<BoxColliderComponent>()
            ? shooter.getComponent<BoxColliderComponent>().size_
            : getVisualSize(shooter);

        footprint = footprint.componentWiseMul(transform.scale_);

        const sf::Vector2f centre = transform.position_ + footprint / 2.f;

        const sf::Vector2f offset = {
            direction.x * (footprint.x / 2.f + kProjectileSize / 2.f + kSpawnMargin),
            direction.y * (footprint.y / 2.f + kProjectileSize / 2.f + kSpawnMargin)
        };

        // A transform position is the top-left corner, so centre the quad
        return centre + offset - sf::Vector2f(kProjectileSize / 2.f, kProjectileSize / 2.f);
    }

    // Every projectile is a small textured quad, so it is a sprite entity.
    static void spawnProjectile(
        Entity projectile,
        const sf::Vector2f& position,
        const sf::Vector2f& velocity,
        const ProjectileEmitterComponent& emitter
    ) {
        projectile.group("projectiles");
        projectile.addComponent<TransformComponent>(position, sf::Vector2f(1.0, 1.0), 0.0);
        projectile.addComponent<RigidBodyComponent>(velocity);
        projectile.addComponent<SpriteComponent>("bullet-image", sf::Vector2f(kProjectileSize, kProjectileSize), sf::Vector2i(4, 4), sf::Vector2i(0, 0), false);
        projectile.addComponent<BoxColliderComponent>(sf::Vector2f(kProjectileSize, kProjectileSize));
        projectile.addComponent<ProjectileComponent>(emitter.is_friendly_, emitter.hit_percent_damage_, emitter.projectile_duration_);
    }

    void onKeyPressed(KeyPressedEvent& event) {

        sf::Keyboard::Scancode key_code = sf::Keyboard::delocalize(event.pressed_key_);

        if (key_code == sf::Keyboard::Scancode::Space) {
            for (auto entity : getSystemEntities()) {
                if (entity.hasTag("player")) {
                    const auto projectileEmitter = entity.getComponent<ProjectileEmitterComponent>();

                    // Fire the way the entity is moving...
                    sf::Vector2f direction(0.f, 0.f);

                    if (entity.hasComponent<RigidBodyComponent>()) {
                        const auto& rigidbody = entity.getComponent<RigidBodyComponent>();
                        direction = { sign(rigidbody.velocity_.x), sign(rigidbody.velocity_.y) };
                    }

                    // ...or, standing still, the way it last faced. Without
                    // this the shot had zero velocity and sat on the shooter.
                    if (direction == sf::Vector2f(0.f, 0.f) &&
                        entity.hasComponent<KeyboardControlledComponent>()) {
                        direction = entity.getComponent<KeyboardControlledComponent>().facing_;
                    }

                    const sf::Vector2f projectile_velocity = {
                        projectileEmitter.projectile_velocity_.x * direction.x,
                        projectileEmitter.projectile_velocity_.y * direction.y
                    };

                    // Create new projectile entity and add it to the world
                    Entity projectile = entity.registry_->createEntity();
                    spawnProjectile(projectile, spawnPosition(entity, direction), projectile_velocity, projectileEmitter);
                }
            }
        }
    }

	void update(float delta_time, std::unique_ptr<Registry>& registry)
	{
		// Loop all entities that the system is interested in
        for (auto entity : getSystemEntities()) {

            auto& projectileEmitter = entity.getComponent<ProjectileEmitterComponent>();

            // If emission frequency is zero, bypass re-emission logic
            if (projectileEmitter.repeat_frequency_ == 0) {
                continue;
            }

            projectileEmitter.elapsed_since_last_emission_ += delta_time;

            // Check if its time to re-emit a new projectile
            if (projectileEmitter.elapsed_since_last_emission_
                >= projectileEmitter.repeat_frequency_) {

                // Automatic fire always flies along the emitter's velocity
                const sf::Vector2f direction = {
                    sign(projectileEmitter.projectile_velocity_.x),
                    sign(projectileEmitter.projectile_velocity_.y)
                };

                // Add a new projectile entity to the registry
                Entity projectile = registry->createEntity();
                spawnProjectile(projectile, spawnPosition(entity, direction), projectileEmitter.projectile_velocity_, projectileEmitter);

                // Update the projectile emitter component last emission to the current milliseconds
                projectileEmitter.elapsed_since_last_emission_ -=
                    projectileEmitter.repeat_frequency_;
            }
        }
	}
};
