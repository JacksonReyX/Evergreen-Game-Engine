#pragma once

#include <iostream>
#include "../ECS/ECS.h"
#include "../Game/game.h"
#include "../Components/ProjectileComponent.h"

class ProjectileLifecycleSystem : public System {
public:
    ProjectileLifecycleSystem() {
        requiredComponent<ProjectileComponent>();
    }

    void update(float delta_time) {
        for (auto entity : getSystemEntities()) {
            auto& projectile = entity.getComponent<ProjectileComponent>();

            projectile.elapsed_time_ += delta_time;

            // Kill projectile after reaching its lifetime
            if (projectile.elapsed_time_ >= projectile.duration_)
            {
                entity.kill();
            }
        }
    }
};