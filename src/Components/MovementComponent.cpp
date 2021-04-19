#include "Components/MovementComponent.h"


#include <any>
#include <random>
#include <string>
#include <SFML/Window/Mouse.hpp>
#include <Tools/VectorTools.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>


#include "GameWorld.h"
#include "GameObjects/Player.h"
#include "Managers/InputManager.h"
#include "Tools/Print.h"

MovementComponent::MovementComponent()
{
    //offset pour que le nez du vaisseau soit vers la souris
    offsetPos.x = 100 * 0.5f / 2;
    offsetPos.y = 100 * 0.5f / 2;

    InputManager::GetSignal().Connect<MovementComponent>(this, &MovementComponent::OnInputForward);
}

void MovementComponent::TickComponent(int64_t deltaTime)
{
    auto mousePos = GameWorld::cursorPos;
    auto pos = Owner->position;

    //distance vers la souris
    float deltaPosX = mousePos.x - (pos.x + offsetPos.x);
    float deltaPosY = mousePos.y - (pos.y + offsetPos.y);

    //on normalise cette distance
    sf::Vector2f normDelta = VectorTools::NormaliseVector(sf::Vector2f(deltaPosX, deltaPosY));

    //rotation pour se tourner vers la souris
    float rot = std::atan2(deltaPosY, deltaPosX) * 180 / std::_Pi;
    Owner->rotation = rot + offsetAngle;

    // //si on veut avancer
    // if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    // {
    //     //avant d'appliquer directement l'input, on va tester cette acceleration
    //     sf::Vector2f acceleration = inertia;
    //     acceleration.x += normDelta.x * speed * deltaTime * 0.0001f;
    //     acceleration.y += normDelta.y * speed * deltaTime * 0.0001f;
    //
    //     //ton vérifie que l'acceleration ne sera pas trop grande avant de l'appliquer
    //     if (VectorTools::Length(acceleration) < maxVelocity)
    //     {
    //         inertia = acceleration;
    //     }
    // }

    //si on veut avancer
    if (moveTowardMouse)
    {
        //avant d'appliquer directement l'input, on va tester cette acceleration
        sf::Vector2f acceleration = inertia;
        acceleration.x += normDelta.x * speed * deltaTime * 0.0001f;
        acceleration.y += normDelta.y * speed * deltaTime * 0.0001f;

        //ton vérifie que l'acceleration ne sera pas trop grande avant de l'appliquer
        if (VectorTools::Length(acceleration) < maxVelocity)
        {
            inertia = acceleration;
        }
    }

    //la force de ralentissement
    float dragForce = 1 - (drag * (deltaTime / 1000.f));

    //on applique cette force, proche de 0,999
    inertia *= dragForce;

    //on set la position, toujours en fonction du deltatime
    Owner->position = pos + (inertia * (deltaTime * 1.f));


    /*
     * Check for side wrap of the player's position. TP from one side of the window to the other
     */

    auto window = GameWorld::window;

    int leftBorder = 0;
    int topBorder = 0;
    int rightBorder = leftBorder + window->getSize().x;
    int bottomBorder = topBorder + window->getSize().y;

    //si on est trop à gauche on TP à droite
    if (Owner->position.x < leftBorder)
    {
        Owner->position.x = rightBorder;
    }
    if (Owner->position.y < topBorder)
    {
        Owner->position.y = bottomBorder;
    }
    if (Owner->position.x > rightBorder)
    {
        Owner->position.x = leftBorder;
    }
    if (Owner->position.y > bottomBorder)
    {
        Owner->position.y = topBorder;
    }
}

void MovementComponent::OnInputForward(std::any i)
{
    moveTowardMouse = false;
    
    std::string s = std::any_cast<const char*>(i);
    if (s == "forward")
    {
        moveTowardMouse = true;
    }

}
