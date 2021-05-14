#include "Components/LifeComponent.h"


#include "Enemy.h"
#include "GameObjects/GameObject.h"
#include "Managers/ScoreManager.h"
#include "Tools/Print.h"

void LifeComponent::TickComponent(int64_t deltaTime)
{
    
}

float LifeComponent::ModifyHealth(float modification)
{
    m_currentHealth += modification;

    //clamp de la vie
    if(m_currentHealth > m_maxHealth)
        m_currentHealth = m_maxHealth;

    if(m_currentHealth < 0)
    {
        Print::PrintLog(typeid(*m_owner).name()," is dead ! ");
        
        m_currentHealth = 0;
        if(dynamic_cast<Enemy*>(m_owner))
        {
            ScoreManager::ModifyScore(1);//une façon d'augmenter le score rapide mais on peut faire mieux
        }
        m_owner->Deactivate();
    }
    // Print::PrintLog("modified health, new life is : ",m_currentHealth);
    return m_currentHealth;
}
