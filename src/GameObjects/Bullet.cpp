#include "GameObjects/Bullet.h"
#include "GameWindow.h"
#include "StaticData.h"
#include "Components/CollisionHandler.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Character.h"
#include "Managers/TextureManager.h"
#include "Tools/SMath.h"

Bullet::Bullet(float delay, sf::Vector2f position, float rotation, float scale, sf::Vector2f offsetPos)
	: GameObject(position, offsetPos, scale, rotation)
	, m_autoDestroyDelay(delay)
{
	std::cout << "New Bullet " << std::endl;
	SetRenderHandler(TextureManager::GetTexturePtr(TextureManager::ETextures::Bullet), "bullet", 2);
	//m_renderHandler = new RenderHandler(this, TextureManager::GetTexturePtr(TextureManager::ETextures::Bullet), "bullet", 2);
	//m_renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::ETextures::Bullet), "bullet", 2);

	auto* Sprite = GetRenderHandler()->GetRenderedItemWithKey<sf::Sprite>("bullet");
	if (Sprite)
	{
		Sprite->setScale(sf::Vector2f(scale, scale));
		Sprite->setOrigin(10, 5);
	}

	//const auto Tmp = std::vector<sf::Vector2f>{ sf::Vector2f(9.0f, 0.0f), sf::Vector2f(0.0f, 4.0f), sf::Vector2f(-9.0f, 0.0f), sf::Vector2f(0.0f, 4.0f) };
	//SetCollisionHandler(CollisionType::BonusChannel, StaticData::BulletCollision, 10);
}

void Bullet::Activate(float delay, sf::Vector2f position, float rotation, float scale, sf::Vector2f offsetPos)
{
	m_autoDestroyDelay = delay;
	SetRenderHandler(TextureManager::GetTexturePtr(TextureManager::ETextures::Bullet), "bullet", 2);
	auto* Sprite = GetRenderHandler()->GetRenderedItemWithKey<sf::Sprite>("bullet");
	if (Sprite)
	{
		Sprite->setScale(sf::Vector2f(scale, scale));
		Sprite->setOrigin(10, 5);
	}
	//SetCollisionHandler(CollisionType::BonusChannel, StaticData::BulletCollision, 10);
	GameObject::Activate(position, offsetPos, scale, rotation);
}

void Bullet::Deactivate()
{
	m_timer = 0.f;
	m_autoDestroyDelay = 0;
	m_speedMultiplier = 1.f;
	m_damageMultiplier = 1.f;
	m_speed = 0.5f;
	m_timer = 0.f;
	m_damage = 1.f;
	GameObject::Deactivate();
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
