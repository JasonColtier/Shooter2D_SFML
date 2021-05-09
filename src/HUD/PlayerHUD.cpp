#include "HUD/PlayerHUD.h"

#include "GameWindow.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Player.h"
#include "Managers/ScoreManager.h"

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
    
    renderHandler->AddText("0","scoreText",3,sf::Vector2f(GameWindow::sizeWindow.x-100,0));

    ScoreManager::GetSignal().Connect<PlayerHUD>(this, &PlayerHUD::HandleChangeScore);

}

void PlayerHUD::Tick(int64_t deltaTime)
{
    GameObject::Tick(deltaTime);

    healthBar->setScale(player->lifeComponent->currentHealth/player->lifeComponent->maxHealth,1);
    
}

void PlayerHUD::HandleChangeScore(int score)
{
    renderHandler->GetText("scoreText")->setString(std::to_string(score));
}
