#ifndef SHOOTCOMPONENT_H
#define SHOOTCOMPONENT_H
#include <cstdint>

#include "Component.h"
#include "Managers/InputManager.h"

class Bullet;

// typedef class InputManager InputMapping;

class ShootComponent : public Component
{
public:
    ShootComponent();
    ~ShootComponent() = default;
    
    void TickComponent(int64_t deltaTime = 0) override;

    void ShootBullet(int initialAngle);

    

    void OnInputChanged(InputMapping input);

private:
    bool wantToShoot = false;

    float timer = 0;
    float fireRate = 1.f;
    int shootNumber = 5;
};
#endif

