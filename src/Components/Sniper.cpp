#include "Components/Sniper.h"
#include "GameWindow.h"
#include "StaticData.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/SniperBullet.h"
#include "Managers/AudioManager.h"
#include "GameObjects/Player.h"

Sniper::Sniper()
{
	m_shootNumber = 1;
	m_fireRate = 10.f;
	m_dispersion = 0.f;
}

void Sniper::ShootBullet(int initialAngle)
{
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
	//if(dynamic_cast<Player*>(m_owner) && E)
	NewBullet->SetCollisionHandler(ColType, StaticData::BulletCollision, 9.f, ExcludeColType);
	//bullet->GetCollisionHandler()->m_eType = CollisionType::PlayerProjectileChannel;
	//bullet->GetCollisionHandler()->m_lExcludedCollisionType = std::vector<CollisionType>({ CollisionType::PlayerChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel });
	AudioManager::PlaySound(AudioManager::ESounds::FireBullet, 10);
}
