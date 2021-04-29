#pragma once
#include "ShootComponent.h"

class Sniper : public ShootComponent
{
public:
    Sniper();

    void ShootBullet(int initialAngle) override;
};
