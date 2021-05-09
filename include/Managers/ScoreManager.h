﻿#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include "Signal.h"

class ScoreManager
{
public:
    static void ModifyScore(int modif);

    //donne le signal émit par cette classe
    static Signal<int>& GetSignal()
    {
        return m_signal;
    }

    inline static Signal<int> m_signal;

private:
    static inline int score;

};
#endif