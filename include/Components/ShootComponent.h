#ifndef SHOOTCOMPONENT_H
#define SHOOTCOMPONENT_H
#include <cstdint>

#include "Component.h"

class Bullet;

class ShootComponent : public Component
{
public:
    ShootComponent();

    Bullet* bullet;
    virtual void UpdateComponent(int64_t deltaTime) override;

private:
    bool test = false;
};
#endif

