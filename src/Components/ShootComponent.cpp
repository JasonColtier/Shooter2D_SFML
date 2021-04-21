#include "Components/ShootComponent.h"


#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "GameLevel.h"
#include "GameWorld.h"
#include "Tools/Print.h"
#include "GameObjects/Bullet.h"
#include "Managers/InputManager.h"


ShootComponent::ShootComponent()
{
    activateTick = true;

    InputManager::GetSignal().Connect<ShootComponent>(this, &ShootComponent::OnInputChanged);
}


void ShootComponent::TickComponent(int64_t deltaTime)
{
    Component::TickComponent(deltaTime);

    if(wantToShoot)
    {
        timer += deltaTime; 
        if(timer >= fireRate * 100000)
        {
            timer = 0;
            ShootBullet();
        }
    }
    
}

void ShootComponent::ShootBullet()
{
    Print::PrintLog("shoot");
    Bullet* bullet = GameWorld::GetGameLevel()->SpawnObject<Bullet>();
    bullet->position = Owner->position;
    bullet->rotation = Owner->rotation - 90;
}

void ShootComponent::OnInputChanged(InputMapping input)
{
    if (input.first == Shoot)
    {
        ShootBullet();
        wantToShoot = input.second;
    }
}
