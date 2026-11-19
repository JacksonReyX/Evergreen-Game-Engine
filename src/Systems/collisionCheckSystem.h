//
//#
//
#include "../Components/BoxColliderComponent.h"
#include "../Components/TransformComponent.h"
#include "../Events/CollisionEvent.h"
#include "../EventBus/EventBus.h"


class CollisionCheckSystem : public System {
    public:
        CollisionCheckSystem() {
            requiredComponent<BoxColliderComponent>();
        }

    void update(std::unique_ptr<EventBus>& event_bus) {
            //gets all entities
            for (auto a : getSystemEntities()) {
                auto& a_transform = a.getComponent<TransformComponent>();
                auto a_collider = a.getComponent<BoxColliderComponent>();
                //gets all entities a second time to compare them for collision
                for (auto b : getSystemEntities()) {
                    auto& b_transform = b.getComponent<TransformComponent>();
                    auto b_collider = b.getComponent<BoxColliderComponent>();
                    //doesn't resolve or check collision if the entity is being compared to itself
                    if (a == b) {
                        continue;
                    }
                    //use transform position and collider size to make a rectangle of the collision box that moves with the player
                    raylib::Rectangle a_CollisionRect = raylib::Rectangle(a_transform.position_.x + a_collider.offset_.x, a_transform.position_.y + a_collider.offset_.y, a_collider.size_.x, a_collider.size_.y);
                    raylib::Rectangle b_CollisionRect = raylib::Rectangle(b_transform.position_.x + b_collider.offset_.x, b_transform.position_.y + b_collider.offset_.y, b_collider.size_.x, b_collider.size_.y);
                    //checks if the rectangles are colliding
                    if (CheckCollisionRecs(a_CollisionRect, b_CollisionRect))
                    {
                        //event_bus->emitEvent<CollisionEvent>(a, b);
                    }

                }
            }
        }

    //draws collision area
    void DrawCollisionRectangles() {
            for (auto a : getSystemEntities()) {
                auto& a_transform = a.getComponent<TransformComponent>();
                auto a_collider = a.getComponent<BoxColliderComponent>();

                for (auto b : getSystemEntities()) {
                    auto& b_transform = b.getComponent<TransformComponent>();
                    auto b_collider = b.getComponent<BoxColliderComponent>();
                    if (a == b) {
                        continue;
                    }
                    raylib::Rectangle a_CollisionRect = raylib::Rectangle(a_transform.position_.x + a_collider.offset_.x, a_transform.position_.y + a_collider.offset_.y, a_collider.size_.x, a_collider.size_.y);
                    raylib::Rectangle b_CollisionRect = raylib::Rectangle(b_transform.position_.x + b_collider.offset_.x, b_transform.position_.y + b_collider.offset_.y, b_collider.size_.x, b_collider.size_.y);
                    //checks if the rectangles are colliding
                    if (CheckCollisionRecs(a_CollisionRect, b_CollisionRect)) {
                        raylib::Rectangle collisionRect = GetCollisionRec(a_CollisionRect, b_CollisionRect);
                        DrawRectangleRec(collisionRect, raylib::BLUE);
                    }


                }
            }
        }




};