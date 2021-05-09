#include "GameObjects/BackgroundTexture.h"
#include "Components/RenderHandler.h"

//todo Game object tout court ?
BackgroundTexture::BackgroundTexture()
{
    renderHandler = new RenderHandler(this,TextureManager::GetTexturePtr(TextureManager::SpaceBackground),"bg",0);

    auto sprite = renderHandler->GetSprite("bg");

    if (sprite)
    {
        sprite->setOrigin(sf::Vector2f(0, 0));
        sprite->setScale(sf::Vector2f(1, 1));
    }
}
