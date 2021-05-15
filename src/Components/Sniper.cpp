#include "Components/Sniper.h"
#include "GameWindow.h"
#include "GameObjects/SniperBullet.h"

Sniper::Sniper()
{
    m_shootNumber = 1;
    m_fireRate = 10.f;
    m_dispersion = 0.f;
    m_range = 10000.f;
}

void Sniper::ShootBullet(int initialAngle)
{
    auto* bullet = GameWindow::GetGameLevel()->SpawnActor<SniperBullet>(Owner->m_position);
    //bullet->m_position = Owner->m_position;
    bullet->m_rotation = Owner->m_rotation + initialAngle;
}
