#include "GameObjects/BackgroundTexture.h"
#include "Components/RenderHandler.h"
#include "Managers/TextureManager.h"

//todo Game object tout court ?
BackgroundTexture::BackgroundTexture(sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation) :GameObject(position, offsetPos, scale, rotation)
{
	m_renderHandler = new RenderHandler(this, TextureManager::GetTexturePtr(TextureManager::ETextures::SpaceBackground), "bg", 0);

	auto* Sprite = m_renderHandler->GetSprite("bg");

	if (Sprite == nullptr)
	{
		Sprite->setOrigin(sf::Vector2f(0, 0));
		Sprite->setScale(sf::Vector2f(1, 1));
	}
}