#include "Components/MovementComponent.h"


#include <any>
#include <random>
#include <string>
#include <SFML/Window/Mouse.hpp>
#include <Tools/VectorTools.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameWindow.h"
#include "GameObjects/GameObject.h"
#include "Managers/InputManager.h"
#include "Tools/Print.h"

MovementComponent::MovementComponent()
{

    InputManager::GetSignal().Connect<MovementComponent>(this, &MovementComponent::OnInputChanged);
}

void MovementComponent::TickComponent(int64_t deltaTime)
{
    auto mousePos = GameWindow::cursorPos;
    auto pos = Owner->position;

    //distance vers la souris
    const auto deltaPosX = mousePos.x - (pos.x + Owner->offsetPos.x);
    const auto deltaPosY = mousePos.y - (pos.y + Owner->offsetPos.y);

    //on normalise cette distance
    const sf::Vector2f normDelta = VectorTools::NormaliseVector(sf::Vector2f(deltaPosX, deltaPosY));

    //rotation pour se tourner vers la souris
    const float rot = std::atan2(deltaPosY, deltaPosX) * 180 / std::_Pi;
    Owner->rotation = rot + offsetAngle;

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
    const auto dragForce = 1 - (drag * (deltaTime / 1000.f));

    //on applique cette force, proche de 0,999
    inertia *= dragForce;

    //on set la position, toujours en fonction du deltatime
    Owner->position = pos + (inertia * (deltaTime * 1.f));


    /*
     * Check for side wrap of the player's position. TP from one side of the window to the other
     */

    auto window = GameWindow::window;

    const int leftBorder = 0;
    const int topBorder = 0;
    const int rightBorder = leftBorder + window->getSize().x;
    const int bottomBorder = topBorder + window->getSize().y;

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

void MovementComponent::OnInputChanged(const InputMapping input)
{
    //si on a appuyé ou relaché la touche pour bouger
    if (input.first==Forward)
    {
        // Print::PrintLog("pressed forward : ",input.second);

        moveTowardMouse = input.second;
    }
}
