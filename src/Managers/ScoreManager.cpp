#include "Managers/ScoreManager.h"

#include "Tools/Print.h"

void ScoreManager::ModifyScore(int modif)
{
    score += modif;
    
    m_signal(score);
}

