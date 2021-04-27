#include "Components/Sniper.h"
#include "Components/RenderHandler.h"
#include "GameWindow.h"
#include "GameObjects/Bullet.h"

Sniper::Sniper()
{
    g_shootNumber = 1;
    g_fireRate = 10.f;
    g_dispersion = 0.f;
}

void Sniper::ShootBullet(int initialAngle)
{
    Bullet* bullet = GameWindow::GetGameLevel()->SpawnActor<Bullet>();
    bullet->position = Owner->position;
    bullet->rotation = Owner->rotation + initialAngle;
    bullet->renderHandler->sprite.setScale(sf::Vector2f(10,10));//TODO mieux ?
    bullet->speedMultiplier = 3;
}
