#include "GameObjects/BackgroundTexture.h"

BackgroundTexture::BackgroundTexture()
{
    renderComponent = new RenderComponent(this,TextureManager::GetTexturePtr(TextureManager::SpaceBackground));
    renderComponent->sprite.setOrigin(sf::Vector2f(0, 0));
    renderComponent->sprite.setScale(sf::Vector2f(1, 1));
}
