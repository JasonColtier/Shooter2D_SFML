#include "HUD/PlayerHUD.h"

#include <SFML/Graphics/Text.hpp>

#include "GameWindow.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Player.h"
#include "Managers/ScoreManager.h"
#include "Managers/TextureManager.h"

PlayerHUD::PlayerHUD(sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation) : GameObject(position, offsetPos, scale, rotation)
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

	m_renderHandler->AddText("deltatime : ","deltatimeText",3,sf::Vector2f(20,20),sf::Color::Cyan,15);
	m_deltatimeText = m_renderHandler->GetRenderedItemWithKey<sf::Text>("deltatimeText");
}

void PlayerHUD::Tick(int64_t deltaTime)
{
	GameObject::Tick(deltaTime);
	m_healthBar->setScale(m_player->m_lifeComponent->m_currentHealth / m_player->m_lifeComponent->m_maxHealth, 1);
	std::string tmp = "deltatime : ";
	m_deltatimeText->setString(tmp.append(std::to_string(deltaTime)));
}

void PlayerHUD::_HandleChangeScore(const int score) const
{
	m_renderHandler->GetRenderedItemWithKey<sf::Text>("scoreText")->setString(std::to_string(score));
}
