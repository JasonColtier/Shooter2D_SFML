#include "HUD/PlayerHUD.h"

#include "GameWindow.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Player.h"

PlayerHUD::PlayerHUD()
{
    player = GameWindow::GetGameLevel()->player;

    renderHandler = new RenderHandler(this,TextureManager::GetTexturePtr(TextureManager::HealthBar),"healthBar",4);

    renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::HealthBarBG),"HealthBarBG",3);

    
    
    healthBar = renderHandler->GetSprite("healthBar");

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
