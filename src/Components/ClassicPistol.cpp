#include "Components/ClassicPistol.h"
#include "GameWindow.h"
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
	auto* NewBullet = GameWindow::GetGameLevel()->SpawnActor<Bullet>();
	NewBullet->m_position = Owner->m_position;
	NewBullet->m_rotation = Owner->m_rotation + static_cast<float>(initialAngle);
	NewBullet->m_collisionHandler->m_eType = CollisionType::PlayerProjectileChannel;
	NewBullet->m_collisionHandler->m_lExcludedCollisionType = new std::vector<CollisionType>({CollisionType::PlayerChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel });
	AudioManager::PlaySound(AudioManager::ESounds::FireBullet, 10);
}