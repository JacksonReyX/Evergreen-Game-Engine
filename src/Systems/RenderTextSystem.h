#pragma once
#include <iostream>
#include "../ECS/ECS.h"
#include "../Components/TextLabelComponent.h"

#include <SFML/Graphics.hpp>
#include "../AssetStore/AssetStore.h"


class RenderTextSystem : public System
{
public:
	RenderTextSystem()
	{
		requiredComponent<TextLabelComponent>();
	}

	void update(sf::RenderWindow* window, std::unique_ptr<AssetStore>& assetStore)
	{
        for (auto entity : getSystemEntities()) {
            const auto textlabel = entity.getComponent<TextLabelComponent>();

			sf::Text text(assetStore->getFont(textlabel.asset_id_)); // a font is required to make a text object

			// set the string to display
			text.setString(textlabel.text_);

			// set the character size
			text.setCharacterSize(textlabel.size_); // in pixels, not points!

			// set the color
			text.setFillColor(textlabel.color_);
			
			// Get the actual rendered bounds of the text
			const sf::FloatRect bounds = text.getLocalBounds();

			// Put the origin at the center of the text
			text.setOrigin(sf::Vector2f(
				bounds.position.x + bounds.size.x / 2.0f,
				bounds.position.y + bounds.size.y / 2.0f
			));

			text.setPosition(textlabel.position_);

			// inside the main loop, between window.clear() and window.display()
			window->draw(text);
        }
	}
};