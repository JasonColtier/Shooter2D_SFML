#include "Components/ShotGun.h"
#include "GameWindow.h"
#include "StaticData.h"
#include "GameObjects/Bullet.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/Player.h"



void ShotGun::ShootBullet(int initialAngle)
{
	auto* NewBullet = GameWindow::GetGameLevel()->SpawnActor<Bullet>(0.4f, m_owner->m_position, m_owner->m_rotation + static_cast<float>(initialAngle), 1.f);
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
	NewBullet->SetCollisionHandler(ColType, StaticData::BulletCollision, 9.f, ExcludeColType);

	//bullet->GetCollisionHandler()->m_eType = CollisionType::EnemyProjectileChannel;
	//bullet->GetCollisionHandler()->m_lExcludedCollisionType = std::vector<CollisionType>({ CollisionType::EnemyChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel });
}
