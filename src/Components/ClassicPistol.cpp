#include "Components/ClassicPistol.h"
#include "GameWindow.h"
#include "StaticData.h"
#include "GameObjects/Bullet.h"
#include "Managers/AudioManager.h"
#include "Components/CollisionHandler.h"

ClassicPistol::ClassicPistol()
{
	m_shootNumber = 1;
	m_fireRate = 2.f;
	m_dispersion = 15.f;
}

void ClassicPistol::ShootBullet(const int initialAngle)
{
	auto* NewBullet = GameWindow::GetGameLevel()->SpawnActor<Bullet>(0.f, m_owner->m_position, m_owner->m_rotation + static_cast<float>(initialAngle));
	CollisionType ColType;
	std::vector<CollisionType> ExcludeColType;
	if (m_isPlayer)
	{
		ColType = CollisionType::PlayerProjectileChannel;
		ExcludeColType = std::vector<CollisionType>({ CollisionType::PlayerChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel });
	}
	else
	{
		ColType = CollisionType::EnemyProjectileChannel;
		ExcludeColType = std::vector<CollisionType>({ CollisionType::EnemyChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel });
	}
	NewBullet->SetCollisionHandler(ColType, StaticData::BulletCollision, 9.f, ExcludeColType);
	//NewBullet->m_position = m_owner->m_position;
	//NewBullet->m_rotation = m_owner->m_rotation + static_cast<float>(initialAngle);
	//NewBullet->GetCollisionHandler()->m_eType = CollisionType::PlayerProjectileChannel;
	//NewBullet->GetCollisionHandler()->m_lExcludedCollisionType = std::vector<CollisionType>({ CollisionType::PlayerChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel });
	AudioManager::PlaySound(AudioManager::ESounds::FireBullet, 10);
}