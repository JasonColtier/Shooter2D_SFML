﻿#include "GameObjects/Bullet.h"

#include "GameObjects/Enemy.h"
#include "GameWindow.h"
#include "Components/CollisionHandler.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Character.h"

#define PI 3.14159265f

Bullet::Bullet()
{
	m_renderHandler = new RenderHandler(this);
	m_renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::ETextures::Bullet), "bullet", 2);

	auto* Sprite = m_renderHandler->GetRenderedItemWithKey<sf::Sprite>("bullet");
	if (Sprite)
	{
		Sprite->setScale(sf::Vector2f(m_scale, m_scale));
		Sprite->setOrigin(10, 5);
	}

	auto* Tmp = new std::vector<sf::Vector2f>{ sf::Vector2f(0.0f, -4.0f), sf::Vector2f(0.0f, 9.0f), sf::Vector2f(0.0f, 4.0f), sf::Vector2f(0.0f, -9.0f) };
	m_collisionHandler = new CollisionHandler(this, CollisionType::BonusChannel, new std::vector<CollisionType>(), &m_rotation, 10, &m_position, Tmp);
}

void Bullet::Tick(const int64_t deltaTime)
{
	if (m_autoDestroyDelay > 0)
	{
		m_timer += static_cast<float>(deltaTime);
		if (m_timer > m_autoDestroyDelay * 1000000)
		{
			Deactivate();
			return;
		}
	}
	const sf::Vector2f forward(cosf(m_rotation * PI / 180.f), sinf(m_rotation * PI / 180.f));

	m_position += (forward / 1000.f * (static_cast<float>(deltaTime) * 1.f)) * GetSpeed();

	if (!GameWindow::CheckIfInsideWindow(this))
	{
		Deactivate();
	}

	GameObject::Tick(deltaTime);
}