#ifndef SHOOTBULLETCOMPONENT_H
#define SHOOTBULLETCOMPONENT_H
#include "ShootComponent.h"

class ShootBulletComponent : public ShootComponent
{
public:

    virtual void ShootBullet(int initialAngle) override;

    virtual float GetWeaponFireRate() const override;
    virtual float GetWeaponShootNumber() const override;

private:

    float myFireRate = 1.5f;
    float myShootNumber = 1;
};

#endif
