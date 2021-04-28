#ifndef LIFECOMPONENT_H
#define LIFECOMPONENT_H
#include "Component.h"

class LifeComponent : public Component
{
public:

    LifeComponent() = default;
    void TickComponent(int64_t deltaTime) override;
    
    float ModifyHealth(float modification);

    float maxHealth = 10;
    float currentHealth = maxHealth;
};

#endif

