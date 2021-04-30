#include "Components/LifeComponent.h"

#include "GameObjects/GameObject.h"
#include "Tools/Print.h"

void LifeComponent::TickComponent(int64_t deltaTime)
{
    
}

float LifeComponent::ModifyHealth(float modification)
{
    currentHealth += modification;

    //clamp de la vie
    if(currentHealth > maxHealth)
        currentHealth = maxHealth;

    if(currentHealth < 0)
    {
        currentHealth = 0;
        Owner->Deactivate();
    }

    Print::PrintLog("modified health, new life is : ",currentHealth);
    return currentHealth;
}
