#ifndef SNIPER_H
#define SNIPER_H

#include "ShootComponent.h"
#include "Tools/Print.h"

class Sniper : public ShootComponent
{
public:
    Sniper()
    {
        m_baseShootNumber = 1;
        m_baseFireRate = 18.f;
        m_baseDispersion = 20.f;
    };

    Sniper(ShootComponent& shootComponent) : ShootComponent(shootComponent)
    {
        m_baseShootNumber = 1;
        m_baseFireRate = 18.f;
        m_baseDispersion = 20.f;
    }

    void ShootBullet(int initialAngle) override;
};
#endif // SNIPER_H
