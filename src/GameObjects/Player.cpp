#include "GameObjects/Player.h"

#include <ostream>
#include <random>
#include <valarray>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "GameLevel.h"
#include "GameLoop.h"
#include "Tools/Print.h"
#include "Components/ShootComponent.h"
#include "Tools/VectorTools.h"


Player::Player()
{
    Print::PrintLog("new player");

    RenderComponent* renderComponent = new RenderComponent(this,GameLoop::GetInstance()->window,TextureManager::GetInstance()->GetTexturePtr(TextureManager::Ship));
    renderComponent->sprite.setOrigin(sf::Vector2f(50.f, 50.f));
    renderComponent->sprite.setScale(sf::Vector2f(0.5f, 0.5f));

    AddComponent(renderComponent);

    ShootComponent* shootComponent = new ShootComponent();

    AddComponent(shootComponent);

    //position de départ du vaisseau
    // position = ;

    //offset pour que le nez du vaisseau soit vers la souris
    offsetPos.x = 100 * 0.5f / 2;
    offsetPos.y = 100 * 0.5f / 2;

    
}

void Player::Tick(int64_t deltaTime)
{
    GameObject::Tick(deltaTime);
    
    auto mousePos = GameLoop::GetInstance()->cursorPos;
    auto pos = position;

    //distance vers la souris
    float deltaPosX = mousePos.x - (pos.x + offsetPos.x);
    float deltaPosY = mousePos.y - (pos.y + offsetPos.y);

    //on normalise cette distance
    sf::Vector2f normDelta = VectorTools::NormaliseVector(sf::Vector2f(deltaPosX, deltaPosY));

    //rotation pour se tourner vers la souris
    float rot = std::atan2(deltaPosY, deltaPosX) * 180 / std::_Pi;
    rotation = rot + offsetAngle;

    //si on veut avancer
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
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
    position = pos + (inertia * (deltaTime * 1.f));


    /*
     * Check for side wrap of the player's position. TP from one side of the window to the other
     */
    
    auto window = GameLoop::GetInstance()->window;

    int leftBorder = 0;
    int topBorder = 0;
    int rightBorder = leftBorder + window->getSize().x;
    int bottomBorder = topBorder + window->getSize().y;

    //si on est trop à gauche on TP à droite
    if(position.x < leftBorder)
    {
        position.x = rightBorder;
    }if(position.y < topBorder)
    {
        position.y = bottomBorder;
    }if(position.x > rightBorder)
    {
        position.x = leftBorder;
    }if(position.y > bottomBorder)
    {
        position.y = topBorder;
    }
}


