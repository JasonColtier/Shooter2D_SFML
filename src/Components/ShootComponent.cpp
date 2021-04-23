#include "Components/ShootComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "GameLevel.h"
#include "GameWindow.h"
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
            for (int i = 0; i < shootNumber; ++i)
            {
                int x = (shootNumber - 1) /2; 
                ShootBullet(-90 + ((i-x)*10));

            }
        }
    }
    
}

void ShootComponent::ShootBullet(int initialAngle)
{
    Print::PrintLog("shoot");
    Bullet* bullet = GameWindow::GetGameLevel()->SpawnActor<Bullet>();
    bullet->position = Owner->position;
    bullet->rotation = Owner->rotation + initialAngle;
}

void ShootComponent::OnInputChanged(InputMapping input)
{
    if (input.first == Shoot)
    {
        wantToShoot = input.second;
    }
}
