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

float LifeComponent::ModifyHealth(float modification)
{
    m_currentHealth += modification;

    //clamp de la vie
    if(m_currentHealth > m_maxHealth)
        m_currentHealth = m_maxHealth;

    if(m_currentHealth < 0)
    {
        Print::PrintLog(typeid(*Owner).name()," is dead ! ");
        
        m_currentHealth = 0;
        if(dynamic_cast<Enemy*>(Owner))
        {
            ScoreManager::ModifyScore(1);//une façon d'augmenter le score
			_SpawnBonus();
        }
        Owner->Deactivate();
    }
    // Print::PrintLog("modified health, new life is : ",m_currentHealth);
    return m_currentHealth;
}

void LifeComponent::_SpawnBonus()
{
	//random
	int range = 100 - 1;
	int num = rand() % range;

	if(num <= m_chanceToSpawnBonus)
	{
		GameWindow::GetGameLevel()->SpawnActor<BonusHeal>()->m_position = Owner->m_position;
		Print::PrintLog("spawned bonus !");
	}
}
