#include "Components/ShootComponent.h"


#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "GameLevel.h"
#include "Tools/Print.h"
#include "GameObjects/Bullet.h"

ShootComponent::ShootComponent()
{
    activateTick = true;
}


void ShootComponent::TickComponent(int64_t deltaTime)
{
    Component::TickComponent(deltaTime);
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {

        Bullet* bullet = GameLevel::GetInstance()->SpawnObject<Bullet>();
        bullet->position = Owner->position;
        Print::PrintLog("shoot");
    }
}
