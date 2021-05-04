#include "HUD/PlayerHUD.h"

#include "GameWindow.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Player.h"

PlayerHUD::PlayerHUD()
{
    renderHandler = new RenderHandler(this,TextureManager::GetTexturePtr(TextureManager::HealthBar),"healthBar",3);

    healthBar = renderHandler->GetSprite("healthBar");

    player = GameWindow::GetGameLevel()->player;

    if (healthBar)
    {
        position = sf::Vector2f(GameWindow::sizeWindow.x / 2 - healthBar->getTexture()->getSize().x / 2,GameWindow::sizeWindow.y - 50); 
    }
}

void PlayerHUD::Tick(int64_t deltaTime)
{
    GameObject::Tick(deltaTime);

    healthBar->setScale(player->lifeComponent->currentHealth/player->lifeComponent->maxHealth,1);
    
}
