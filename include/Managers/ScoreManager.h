#pragma once
#include <string>

class ScoreManager
{
public:
    static void ModifyScore(int modif);

    static std::string* GetScoreText();

private:
    static inline int score;
    static inline std::string* scoreText = nullptr;

    
};
