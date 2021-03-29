#pragma once
#include "signal.h"
#include <any>

class TestSignalSimple
{
public:
    TestSignalSimple();
    ~TestSignalSimple() = default;

    //une petite fonction pour tester le signal
    void Test();

    //donne le signal émit par cette classe
    Signal<std::any>& GetSignal()
    {
        return m_signal;
    }

private:
    void Print();//on essayera de s'y connecter plus tard
    std::function<void(std::any)> m_function; //void est le type de retour
    Signal<std::any> m_signal;//notre signal
};
