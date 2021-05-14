#include "Components/ClassicPistol.h"
#include "GameWindow.h"
#include "GameObjects/Bullet.h"
#include "Managers/AudioManager.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/PlayerBullet.h"

ClassicPistol::ClassicPistol()
{
	m_baseShootNumber = 1;
	m_baseFireRate = 2.f;
	m_baseDispersion = 15.f;
}

void ClassicPistol::ShootBullet(const int initialAngle)
{
	auto* NewBullet = GameWindow::GetGameLevel()->SpawnActor<PlayerBullet>(Owner->m_position);
	//NewBullet->m_position = Owner->m_position;
	NewBullet->m_rotation = Owner->m_rotation + static_cast<float>(initialAngle);
	AudioManager::PlaySound(AudioManager::ESounds::FireBullet, 10);
}