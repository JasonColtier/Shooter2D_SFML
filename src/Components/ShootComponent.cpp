#include "Components/ShootComponent.h"


#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "GameLevel.h"
#include "GameObjects/Bullet.h"

ShootComponent::ShootComponent()
{
    activateTick = true;
}

void ShootComponent::UpdateComponent(int64_t deltaTime)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        // if(test)
        //     return;

        test = true;
        
        bullet = new Bullet();
        
        GameLevel::GetInstance();
        GameLevel::GetInstance()->SpawnObject(bullet,sf::Vector2f(deltaTime, deltaTime));
        
        Print::PrintLog("shoot");
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Middle))
    {
        test = false;
    }
}
