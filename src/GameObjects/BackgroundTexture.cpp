#include "GameObjects/BackgroundTexture.h"
#include "Components/RenderHandler.h"

//todo Game object tout court ?
BackgroundTexture::BackgroundTexture()
{
    renderHandler = new RenderHandler(this,TextureManager::GetTexturePtr(TextureManager::SpaceBackground),0);
    renderHandler->sprite.setOrigin(sf::Vector2f(0, 0));
    renderHandler->sprite.setScale(sf::Vector2f(1, 1));
}
