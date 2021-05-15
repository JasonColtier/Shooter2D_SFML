#ifndef SHOTGUN_H
#define SHOTGUN_H
#include "ShootComponent.h"

class ShotGun : public ShootComponent
{
public:
    ShotGun()
    {
        m_baseShootNumber = 5;
        m_baseFireRate = 7.f;
        m_baseDispersion = 10;
    };

    ShotGun(ShootComponent& shootComponent) : ShootComponent(shootComponent)
    {
        m_baseShootNumber = 5;
        m_baseFireRate = 7.f;
        m_baseDispersion = 10;
    };

    void ShootBullet(int initialAngle) override;
};

#endif