#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Components/BoxColliderComponent.h"
#include "../Components/HealthComponent.h"
#include "../Components/ProjectileComponent.h"
#include "../EventBus/EventBus.h"
#include "../Events/CollisionEvent.h"

class DamageSystem : public System {
public:
    DamageSystem() {
        requiredComponent<BoxColliderComponent>();
    }

    void subscribeToEvents(std::unique_ptr<EventBus>& event_bus) {
        event_bus->subscribeToEvent<CollisionEvent>(this, &DamageSystem::onCollision);
    }

    void onCollision(CollisionEvent& event) {
        Entity a = event.a_;
        Entity b = event.b_;

        Logger::Log("The Damage system received an event collision between entities " + std::to_string(a.getId()) + " and " + std::to_string(b.getId()));
       
        if (a.belongsToGroup("projectiles") && b.hasTag("player")) {
            onProjectileHitsPlayer(a, b); // "a" is the projectile, "b" is the player
        }

        if (b.belongsToGroup("projectiles") && a.hasTag("player")) {
            onProjectileHitsPlayer(b, a); // "b" is the projectile, "a" is the player
        }

        if (a.belongsToGroup("projectiles") && b.belongsToGroup("enemies")) {
            onProjectileHitsEnemy(a, b); // "a" is the projectile, "b" is the enemy
        }

        if (b.belongsToGroup("projectiles") && a.belongsToGroup("enemies")) {
            onProjectileHitsEnemy(b, a); // "b" is the projectile, "a" is the enemy
        }
        
        //event.a_.kill();
        //event.b_.kill();
    }

    void onProjectileHitsPlayer(Entity projectile, Entity player) {
        const auto projectileComponent = projectile.getComponent<ProjectileComponent>();

        if (!projectileComponent.is_friendly_) {
            // Reduce the health of the player by the projectile hitPercentDamage
            auto& health = player.getComponent<HealthComponent>();

            // Subtract the health of the player
            health.health_percentage_ -= projectileComponent.hit_percent_damage_;

            // Kills the player when health reaches zero
            if (health.health_percentage_ <= 0) {
                player.kill();
            }

            // Kill the projectile
            projectile.kill();
        }
    }

    void onProjectileHitsEnemy(Entity projectile, Entity enemy) {
        const auto projectileComponent = projectile.getComponent<ProjectileComponent>();

        // Only damage the enemy if projectile is friendly
        if (projectileComponent.is_friendly_) {
            auto& health = enemy.getComponent<HealthComponent>();

            // Subtract from enemy health
            health.health_percentage_ -= projectileComponent.hit_percent_damage_;

            // Kills the enemy if health reaches zero
            if (health.health_percentage_ <= 0) {
                enemy.kill();
            }

            // Destroy projectile
            projectile.kill();
        }
    }
};




