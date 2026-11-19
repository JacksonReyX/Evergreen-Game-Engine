#pragma once
#include "../ECS/ECS.h"
#include "../EventBus/Event.h"

class CollisionEvent : public Event {
public:
    Entity a;
    Entity b;
    CollisionEvent(Entity a_, Entity b_) : a(a_), b(b_) {}
};