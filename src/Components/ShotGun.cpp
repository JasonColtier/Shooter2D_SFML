#include "Components/ShotGun.h"
#include "GameWindow.h"
#include "GameObjects/Bullet.h"


ShotGun::ShotGun()
{
    g_shootNumber = 5;
    g_fireRate = 8.f;
    g_dispersion = 10;
}

void ShotGun::ShootBullet(int initialAngle)
{
    Bullet* bullet = GameWindow::GetGameLevel()->SpawnActor<Bullet>();
    bullet->position = Owner->position;
    bullet->rotation = Owner->rotation + initialAngle;
    bullet->autoDestroyDelay = 0.4f;
}
