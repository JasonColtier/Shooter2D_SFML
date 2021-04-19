#include "Managers/InputManager.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

void InputManager::HandleInputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
        || sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_signal("shoot");
        // m_signal(0);
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        m_signal("forward");
        // m_signal(11);
    }
}
