#include "Components/ShotGun.h"
#include "GameWindow.h"
#include "GameObjects/Bullet.h"
#include "Components/CollisionHandler.h"

ShotGun::ShotGun()
{
	m_shootNumber = 5;
	m_fireRate = 2.f;
	m_dispersion = 10;
}

void ShotGun::ShootBullet(int initialAngle)
{
	auto* bullet = GameWindow::GetGameLevel()->SpawnActor<Bullet>(Owner->m_position);
	//bullet->m_position = Owner->m_position;
	bullet->m_rotation = Owner->m_rotation + static_cast<float>(initialAngle);
	bullet->m_autoDestroyDelay = 0.4f;

	bullet->m_collisionHandler->m_eType = CollisionType::EnemyProjectileChannel;
	bullet->m_collisionHandler->m_lExcludedCollisionType = std::vector<CollisionType>({ CollisionType::EnemyChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel });
}
