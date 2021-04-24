#include "GameWindow.h"
#include <SFML/Graphics/RenderWindow.hpp>



bool GameWindow::CheckIfInsideWindow(GameObject* gameObject)
{
    if (gameObject->position.x < 0
        || gameObject->position.y < 0
        || gameObject->position.x > window->getSize().x
        || gameObject->position.y > window->getSize().y)
    {
        return false;
    }

    return true;
}
