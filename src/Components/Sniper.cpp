#include "Components/Sniper.h"

#include <SFML/Graphics/Sprite.hpp>

#include "GameWindow.h"
#include "StaticData.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/Bullet.h"
#include "Managers/AudioManager.h"
#include "GameObjects/Player.h"


void Sniper::ShootBullet(int initialAngle)
{
	m_baseShootNumber = 1;
	m_baseFireRate = 10.f;
	m_baseDispersion = 20.f;
	
	auto* NewBullet = GameWindow::GetGameLevel()->SpawnActor<Bullet>(0.f, m_owner->m_position, m_owner->m_rotation + initialAngle, 10);
	CollisionType ColType;
	std::vector<CollisionType> ExcludeColType;
	if (dynamic_cast<Player*>(m_owner))
	{
		ColType = CollisionType::PlayerProjectileChannel;
		ExcludeColType = std::vector<CollisionType>({ CollisionType::PlayerChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel });
	}
	else
	{
		ColType = CollisionType::EnemyProjectileChannel;
		ExcludeColType = std::vector<CollisionType>({ CollisionType::EnemyChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel });
	}
	for (auto t : ExcludeColType)
	{
		if (t == CollisionType::EnemyChannel && dynamic_cast<Player*>(m_owner))
		{
			std::cout << "Player fire enemy bullet" << std::endl;
			std::cout << "  " << std::endl;
		}
	}
	NewBullet->SetCollisionHandler(ColType, StaticData::BulletCollision, 9.f, ExcludeColType);
	AudioManager::PlaySound(AudioManager::ESounds::FireBullet, 10);
}
