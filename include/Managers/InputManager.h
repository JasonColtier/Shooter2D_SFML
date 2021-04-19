#pragma once
#include <any>

#include "Signal.h"

class InputManager
{
public:
    InputManager() = default;

    virtual ~InputManager() = default;

    static void HandleInputs();

    //donne le signal émit par cette classe
    static Signal<std::any>& GetSignal()
    {
        return m_signal;
    }

    inline static Signal<std::any> m_signal;//notre signal

};
