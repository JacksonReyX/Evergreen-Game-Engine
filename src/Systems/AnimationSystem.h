#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Game/game.h"
#include "../Components/SpriteComponent.h"
#include "../Components/AnimationComponent.h"
#include "../Components/MoveableComponent.h"


#include "../Logger/Logger.h"

class AnimationSystem : public System
{
public:
	AnimationSystem()
	{
		requiredComponent<TransformComponent>();
		requiredComponent<SpriteComponent>();
		requiredComponent<AnimationComponent>();
	}

	void update()
	{
		// Loop all entities that the system is interested in
		for (auto entity : getSystemEntities())
		{
			auto& animation = entity.getComponent<AnimationComponent>();
			auto& sprite = entity.getComponent<SpriteComponent>();

			if (animation.num_frames_ <= 0)
			{
				continue;
			}

			if (entity.hasComponent<MoveableComponent>()) {

				auto& moveable = entity.getComponent<MoveableComponent>();
				if (moveable.player_moving_) {
					sprite.src_position_.y = sprite.src_size_.y * moveable.direction_;

				}
				else {
					sprite.src_position_.y = sprite.src_size_.y * 4;
				}
			}

			//if one more increment of the tick counter is equal to the ticks per frame
			//then reset the tick counter and set the current frame equal to its starting position
			// if (++animation.tick_counter_ >= animation.ticks_per_frame_) {
			// 	animation.tick_counter_ = 0;
			// 	animation.current_frame_ = (animation.current_frame_ + 1) % animation.num_frames_;
			// }

			if (animation.tick_counter_ % 3 == 0) {
				sprite.src_position_.x = sprite.src_size_.x * animation.current_frame_;
				animation.current_frame_++;
			}

			if (animation.current_frame_ >= animation.num_frames_) {animation.current_frame_ = 1;}
			//else animation.current_frame_ = animation.current_frame_ + 1;
			if (animation.tick_counter_ >= animation.num_frames_*3) {animation.tick_counter_ = 0;}
			//if (animation.tick_counter_ > animation.ticks_per_frame_) {animation.tick_counter_ = 1;}
			animation.tick_counter_ = animation.tick_counter_ + 1;

			
		}
	}
};
