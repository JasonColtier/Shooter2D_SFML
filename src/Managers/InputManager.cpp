#include "Managers/InputManager.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>


void InputManager::HandleInputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
        || sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        SendSignalIfNewInput(shoot, true);
    }
    else
    {
        SendSignalIfNewInput(shoot, false);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        SendSignalIfNewInput(forward, true);
    }
    else
    {
        SendSignalIfNewInput(forward, false);
    }
}

void InputManager::SendSignalIfNewInput(InputMapping& input, bool pressed)
{
    if (pressed && !input.second)
    {
        input.second = true;
        m_inputSignal(input);
    }
    if (!pressed && input.second)
    {
        input.second = false;
        m_inputSignal(input);
    }
}
