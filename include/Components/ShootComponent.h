#ifndef SHOOTCOMPONENT_H
#define SHOOTCOMPONENT_H
#include <cstdint>

#include "Component.h"

class Bullet;

class ShootComponent : public Component
{
public:
    ShootComponent();

    virtual void TickComponent(int64_t deltaTime = 0) override;

private:
    bool test = false;
};
#endif

