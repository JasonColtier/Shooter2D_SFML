#include "Components/Sniper.h"
#include "GameWindow.h"
#include "GameObjects/SniperBullet.h"

Sniper::Sniper()
{
    m_baseShootNumber = 1;
    m_baseFireRate = 18.f;
    m_baseDispersion = 0.f;
}

void Sniper::ShootBullet(int initialAngle)
{
    auto* bullet = GameWindow::GetGameLevel()->SpawnActor<SniperBullet>(Owner->m_position);
    //bullet->m_position = Owner->m_position;
    bullet->m_rotation = Owner->m_rotation + initialAngle;
}
