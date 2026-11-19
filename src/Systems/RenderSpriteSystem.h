#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Components/SpriteComponent.h"
#include "../Components/TransformComponent.h"
#include "../AssetStore/AssetStore.h"
#import "raylib.h"
#include "raylib-cpp.hpp"

////////////////////////////////////////////////////////////////////////////////
// RenderSpriteSystem
////////////////////////////////////////////////////////////////////////////////
// Draws every entity that carries a texture. Primitives are drawn separately
// by the RenderShapeSystem, so an entity may hold both and be drawn twice.
////////////////////////////////////////////////////////////////////////////////
class RenderSpriteSystem : public System
{
public:
	RenderSpriteSystem()
	{
		requiredComponent<TransformComponent>();
		requiredComponent<SpriteComponent>();
	}

	void update(std::unique_ptr<AssetStore>& assetStore, raylib::Camera2D& camera, raylib::Texture2D* texture)
	{
		for (auto entity : getSystemEntities())
		{
			if (true) {
				const auto transform = entity.getComponent<TransformComponent>();
				const auto sprite = entity.getComponent<SpriteComponent>();

				if (!sprite.visible_ || sprite.asset_id_.empty())
				{
					continue;
				}

				raylib::Texture2D* texture = assetStore->getTexture(sprite.asset_id_);

				if (!texture)
				{
					continue;
				}


				// Fall back to the whole texture when no source rectangle was given
				raylib::Rectangle source_rect(sprite.src_position_, sprite.src_size_);

				if (source_rect.GetSize().x <= 0 || source_rect.GetSize().y <= 0)
				{
					source_rect = raylib::Rectangle({ 0, 0 }, raylib::Vector2(texture->GetSize()));
				}

				// Fall back to the source size when no destination size was given
				raylib::Rectangle destination_rect;
				destination_rect.x = transform.position_.x;
				destination_rect.y = transform.position_.y;
				destination_rect.width = sprite.size_.x * transform.scale_.x;
				destination_rect.height = sprite.size_.y * transform.scale_.y;

				 DrawTexturePro(*texture, source_rect, destination_rect, raylib::Vector2(0.f, 0.f), transform.rotation_, raylib::Color::RayWhite());
				if (entity.hasComponent<BoxColliderComponent>()) {
					DrawRectangleLines(destination_rect.x + entity.getComponent<BoxColliderComponent>().offset_.x, destination_rect.y + entity.getComponent<BoxColliderComponent>().offset_.y, entity.getComponent<BoxColliderComponent>().size_.x, entity.getComponent<BoxColliderComponent>().size_.y, raylib::Color::Red());
				}
			}
		}
	}

	void test(std::unique_ptr<AssetStore>& assetStore, raylib::Texture2D* texture) {
		DrawTexturePro(*texture, raylib::Rectangle(0,0,16,16), raylib::Rectangle(50,50, 100, 100), raylib::Vector2(50.f, 50.f), 0.0, raylib::Color::RayWhite());
	}
};
