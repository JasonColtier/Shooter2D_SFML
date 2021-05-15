#ifndef SHOTGUN_H
#define SHOTGUN_H
#include "ShootComponent.h"

class ShotGun : public ShootComponent
{
public:
    ShotGun(Character* characterShooter) : ShootComponent(characterShooter)
    {
        m_baseShootNumber = 5;
        m_baseFireRate = 7.f;
        m_baseDispersion = 10;
        m_range = 450.f;
    };
    ShotGun(ShootComponent& shootComponent) : ShootComponent(shootComponent)
    {
        m_baseShootNumber = 5;
        m_baseFireRate = 7.f;
        m_baseDispersion = 10;
        m_range = 450.f;
    };

    void ShootBullet(int initialAngle) override;
};

#endif