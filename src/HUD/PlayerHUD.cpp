#include "HUD/PlayerHUD.h"

#include "GameWindow.h"
#include "Components/RenderHandler.h"

PlayerHUD::PlayerHUD()
{
    player = GameWindow::GetGameLevel()->player;
}

void PlayerHUD::Tick(int64_t deltaTime)
{
    GameObject::Tick(deltaTime);

    renderHandler = new RenderHandler(this, TextureManager::GetTexturePtr(TextureManager::Ship), 1);
    renderHandler->sprite.setOrigin(sf::Vector2f(50.f, 50.f));
    renderHandler->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
}
