#include "GameObjects/BackgroundTexture.h"
#include "Components/RenderHandler.h"

//todo Game object tout court ?
BackgroundTexture::BackgroundTexture()
{
    m_renderHandler = new RenderHandler(this,TextureManager::GetTexturePtr(TextureManager::ETextures::SpaceBackground),"bg",0);

    auto* Sprite = m_renderHandler->GetSprite("bg");

    if (Sprite == nullptr)
    {
        Sprite->setOrigin(sf::Vector2f(0, 0));
        Sprite->setScale(sf::Vector2f(1, 1));
    }
}