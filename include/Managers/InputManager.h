#pragma once
#include "Signal.h"

#include <any>

#include "Signal.h"
#include "Components/ShootComponent.h"

//une enum pour 
enum InputsEnum
{
    Shoot,
    Forward,
};

typedef std::pair<InputsEnum,bool> InputMapping;

class InputManager
{
public:

    virtual ~InputManager() = default;

    //appelé à chaque tick, check les inputs clavier
    static void HandleInputs();

    //si un input change par rapport à sa valeur actuelle, on émet un signal
    static void SendSignalIfNewInput(InputMapping& input, bool pressed);
    
    //donne le signal émit par cette classe
    static Signal<InputMapping>& GetSignal()
    {
        return m_inputSignal;
    }

    //le signal émit
    inline static Signal<InputMapping> m_inputSignal;

private:

    //nos inputs et leurs valeures 
    inline static InputMapping shoot = std::make_pair(Shoot,false);
    inline static InputMapping forward = std::make_pair(Forward,false);
    InputManager() = default;

    
};
