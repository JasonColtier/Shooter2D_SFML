#include "Components/ShotGun.h"
#include "GameWindow.h"
#include "GameObjects/Bullet.h"
#include "Components/CollisionHandler.h"


void ShotGun::ShootBullet(int initialAngle)
{
	auto* bullet = GameWindow::GetGameLevel()->SpawnActor<Bullet>(m_characterShooter,Owner->m_position);
	//bullet->m_position = Owner->m_position;
	bullet->m_rotation = Owner->m_rotation + static_cast<float>(initialAngle);
	bullet->m_autoDestroyDelay = 0.4f;
}
