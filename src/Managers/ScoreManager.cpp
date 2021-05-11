#include "Managers/ScoreManager.h"

#include "Tools/Print.h"

void ScoreManager::ModifyScore(int modif)
{
    m_score += modif;
    
    m_signal(m_score);
}

