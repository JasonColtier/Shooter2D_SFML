﻿#include "Player.h"


#include <ostream>
#include <random>
#include <valarray>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "GameLevel.h"
#include "GameLoop.h"
#include "Tools/VectorTools.h"


Player::Player()
{
    Print::PrintString("new player");
    texture = TextureManager::GetInstance()->GetTexturePtr(TextureManager::Ship);
    sprite.setTexture(*texture); //déréférencement du pointeur pour accéder à la texture
    sprite.setPosition(sf::Vector2f(300.f, 300.f));
    sprite.setOrigin(sf::Vector2f(50.f, 50.f));
    sprite.setScale(sf::Vector2f(0.5f, 0.5f));

    //offset pour que le nez du vaisseau soit vers la souris
    offsetPos.x = 100 * 0.5f / 2;
    offsetPos.y = 100 * 0.5f / 2;
}

void Player::Tick(int64_t deltaTime)
{
    auto mousePos = GameLoop::GetInstance()->cursorPos;
    auto pos = sprite.getPosition();

    //distance vers la souris
    float deltaPosX = mousePos.x - (pos.x + offsetPos.x);
    float deltaPosY = mousePos.y - (pos.y + offsetPos.y);

    //on normalise cette distance
    sf::Vector2f normDelta = VectorTools::NormaliseVector(sf::Vector2f(deltaPosX, deltaPosY));

    //rotation pour se tourner vers la souris
    float rot = std::atan2(deltaPosY, deltaPosX) * 180 / std::_Pi;
    sprite.setRotation(rot + offsetAngle);

    //si on veut avancer
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        
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
    sprite.setPosition(pos + (inertia * (deltaTime * 1.f)));
}

void Player::Render(sf::RenderWindow* window)
{
    window->draw(sprite);
}
