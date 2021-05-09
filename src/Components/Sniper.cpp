#include "Components/Sniper.h"
#include "Components/RenderHandler.h"
#include "GameWindow.h"
#include "GameObjects/SniperBullet.h"
#include "Managers/AudioManager.h"

Sniper::Sniper()
{
    g_shootNumber = 1;
    g_fireRate = 10.f;
    g_dispersion = 0.f;
}

void Sniper::ShootBullet(int initialAngle)
{
    Bullet* bullet = GameWindow::GetGameLevel()->SpawnActor<SniperBullet>();
    bullet->position = Owner->position;
    bullet->rotation = Owner->rotation + initialAngle;

}
