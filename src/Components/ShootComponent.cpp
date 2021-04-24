#include "Components/ShootComponent.h"
#include "GameLevel.h"
#include "Tools/Print.h"
#include "Managers/InputManager.h"


ShootComponent::ShootComponent()
{
    activateTick = true;

    InputManager::GetSignal().Connect<ShootComponent>(this, &ShootComponent::OnInputChanged);
}


void ShootComponent::TickComponent(int64_t deltaTime)
{
    //si je veux tirer
    if(wantToShoot)
    {
        //boucle pour tirer toutes les X secondes
        timer += deltaTime; 
        if(timer >= g_fireRate * 100000 * GetWeaponFireRate())
        {
            timer = 0;

            //je tire X fois avec un angle différent à chaque fois
            for (int i = 0; i < g_shootNumber + GetWeaponShootNumber(); ++i)
            {
                auto offsetAngle = (g_shootNumber + GetWeaponShootNumber() - 1) /2; 
                ShootBullet(-90 + ((i-offsetAngle)*10));
            }
        }
    }else
    {
        //on continue d'incrémenter le timer si on tire pas pour "charger" les balles et qu'elles partent dès qu'on clic
        if(timer < g_fireRate * 100000 * GetWeaponFireRate())
        {
            timer += deltaTime;
        }
    }
}

void ShootComponent::OnInputChanged(InputMapping input)
{
    if (input.first == Shoot)
    {
        wantToShoot = input.second;
    }
}
