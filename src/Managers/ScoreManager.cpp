#include "Managers/ScoreManager.h"

#include "Tools/Print.h"

void ScoreManager::ModifyScore(int modif)
{
    score += modif;
    scoreText = &std::to_string(score);
    
    Print::PrintLog("current score",score);
}

std::string* ScoreManager::GetScoreText()
{
    scoreText = &std::to_string(score);
    
    return scoreText;
    
}
