#include "HUD/PlayerHUD.h"

#include "GameWindow.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Player.h"

PlayerHUD::PlayerHUD()
{
    
    renderHandler = new RenderHandler(this, TextureManager::GetTexturePtr(TextureManager::HealthBar), 1);

    //je place ma barre au centre en X et avec un offset de 50 du bas
    position = sf::Vector2f(GameWindow::sizeWindow.x / 2 - renderHandler->sprite.getTexture()->getSize().x / 2,GameWindow::sizeWindow.y - 50); 
}

void PlayerHUD::Tick(int64_t deltaTime)
{
    GameObject::Tick(deltaTime);

    renderHandler->sprite.setScale(player->lifeComponent->currentHealth/player->lifeComponent->maxHealth,1);
    
}
