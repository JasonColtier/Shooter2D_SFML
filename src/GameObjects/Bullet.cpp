#include "GameObjects/Bullet.h"

#include "GameObjects/Enemy.h"
#include "GameWindow.h"
#include "StaticData.h"
#include "Components/CollisionHandler.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Character.h"
#include "Managers/TextureManager.h"
#include "Tools/SMath.h"

Bullet::Bullet(Character* characterShooter,sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation, sf::Texture* texture,bool piercing,float autoDestroy)
{
	Activate(characterShooter,position,offsetPos,scale,rotation,texture,piercing);
}

void Bullet::Activate(Character* characterShooter,sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation, sf::Texture* texture, bool piercing,float autoDestroy)
{
	GameObject::Activate(position,offsetPos,scale,rotation);

	m_autoDestroyDelay = autoDestroy;
	m_renderHandler = new RenderHandler(this);
	m_renderHandler->AddSprite(texture, "bullet", 2);
	m_piercing = piercing;
	
	auto* Sprite = m_renderHandler->GetRenderedItemWithKey<sf::Sprite>("bullet");
	if (Sprite)
	{
		Sprite->setScale(sf::Vector2f(m_scale, m_scale));
		Sprite->setOrigin(10, 5);
	}

	m_collisionHandler = new CollisionHandler(this, CollisionType::BonusChannel, std::vector<CollisionType>(), &m_rotation, 10, &m_position, StaticData::BulletCollision);

	if(dynamic_cast<Enemy*>(characterShooter) != nullptr)
	{
		m_collisionHandler->m_eType = CollisionType::EnemyProjectileChannel;
		m_collisionHandler->m_lExcludedCollisionType = std::vector<CollisionType>{CollisionType::EnemyChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel, CollisionType::BonusChannel };
	}else
	{
		m_collisionHandler->m_eType = CollisionType::PlayerProjectileChannel;
		m_collisionHandler->m_lExcludedCollisionType = std::vector<CollisionType>{CollisionType::PlayerChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel, CollisionType::BonusChannel };
	}
}

void Bullet::Deactivate()
{
	m_CharacterShooter = nullptr;
	m_timer = 0;
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
