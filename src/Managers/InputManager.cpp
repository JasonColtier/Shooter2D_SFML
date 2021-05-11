#include "Managers/InputManager.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>


void InputManager::HandleInputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
        || sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        SendSignalIfNewInput(m_shoot, true);
    }
    else
    {
        SendSignalIfNewInput(m_shoot, false);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        SendSignalIfNewInput(m_forward, true);
    }
    else
    {
        SendSignalIfNewInput(m_forward, false);
    }


    // DEBUG
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
    {
        SendSignalIfNewInput(m_debugNum1, true);
    }
    else
    {
        SendSignalIfNewInput(m_debugNum1, false);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
    {
        SendSignalIfNewInput(m_debugNum2, true);
    }
    else
    {
        SendSignalIfNewInput(m_debugNum2, false);
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
