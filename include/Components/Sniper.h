#ifndef SNIPER_H
#define SNIPER_H

#include "ShootComponent.h"

class Sniper : public ShootComponent
{
public:
    Sniper();

    void ShootBullet(int initialAngle) override;
};
#endif // SNIPER_H
