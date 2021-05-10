#include "Components/ShotGun.h"
#include "GameWindow.h"
#include "GameObjects/Bullet.h"
#include "Components/CollisionHandler.h"


ShotGun::ShotGun()
{
    g_shootNumber = 5;
    g_fireRate = 2.f;
    g_dispersion = 10;
}

void ShotGun::ShootBullet(int initialAngle)
{
    Bullet* bullet = GameWindow::GetGameLevel()->SpawnActor<Bullet>();
    bullet->position = Owner->position;
    bullet->rotation = Owner->rotation + initialAngle;
    bullet->autoDestroyDelay = 0.4f;

    bullet->collisionHandler->e_Type = CollisionType::EnemyProjectileChannel;
    bullet->collisionHandler->l_ExcludedCollisionType = new std::vector<CollisionType>({ EnemyChannel, EnemyProjectileChannel, PlayerProjectileChannel });
}
