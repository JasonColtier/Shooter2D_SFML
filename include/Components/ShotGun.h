#ifndef SHOTGUN_H
#define SHOTGUN_H
#include "ShootComponent.h"

class ShotGun : public ShootComponent
{
public:
    ShotGun();

    void ShootBullet(int initialAngle) override;
};

#endif