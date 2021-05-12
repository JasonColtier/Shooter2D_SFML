#include "HUD/PlayerHUD.h"
#include "GameWindow.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Player.h"
#include "Managers/ScoreManager.h"

PlayerHUD::PlayerHUD()
{
	m_player = GameWindow::GetGameLevel()->m_player;

	m_renderHandler = new RenderHandler(this);
	m_renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::ETextures::HealthBarBG), "HealthBarBG", 3);
	m_renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::ETextures::HealthBar), "healthBar", 4);
	m_healthBar = m_renderHandler->GetRenderedItemWithKey<sf::Sprite>("healthBar");

	if (m_healthBar)
	{
		m_position = sf::Vector2f(GameWindow::m_sizeWindow.x / 2 - m_healthBar->getTexture()->getSize().x / 2, GameWindow::m_sizeWindow.y - 50);
	}

	m_renderHandler->AddText("0", "scoreText", 3, sf::Vector2f(GameWindow::m_sizeWindow.x - 100, 0));
	ScoreManager::GetSignal().Connect<PlayerHUD>(this, &PlayerHUD::_HandleChangeScore);
}

void PlayerHUD::Tick(int64_t deltaTime)
{
	GameObject::Tick(deltaTime);
	m_healthBar->setScale(m_player->m_lifeComponent->m_currentHealth / m_player->m_lifeComponent->m_maxHealth, 1);
}

void PlayerHUD::_HandleChangeScore(const int score) const
{
	m_renderHandler->GetRenderedItemWithKey<sf::Text>("scoreText")->setString(std::to_string(score));
}
