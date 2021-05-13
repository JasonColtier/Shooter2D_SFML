#include "Components/LifeComponent.h"



#include "GameWindow.h"
#include "GameObjects/BonusHeal.h"
#include "GameObjects/Enemy.h"
#include "GameObjects/GameObject.h"
#include "Managers/ScoreManager.h"
#include "Tools/Print.h"

void LifeComponent::TickComponent(int64_t deltaTime)
{
    
}

void LifeComponent::ModifyHealth(float modification)
{
    m_currentHealth += modification;

    //clamp de la vie
    if(m_currentHealth > m_maxHealth)
        m_currentHealth = m_maxHealth;

    if(m_currentHealth < 0)
    {
        Print::PrintLog(typeid(*Owner).name()," is dead ! ");
        
        m_currentHealth = 0;
        Owner->Deactivate();
    }
    // Print::PrintLog("modified health, new life is : ",m_currentHealth);
}

