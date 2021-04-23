#include "Components/ShootBulletComponent.h"
#include "GameObjects/GenericBullet.h"
#include "GameWindow.h"


void ShootBulletComponent::ShootBullet(int initialAngle)
{
    // Print::PrintLog("shoot");
    GenericBullet* bullet = GameWindow::GetGameLevel()->SpawnActor<GenericBullet>();
    bullet->position = Owner->position;
    bullet->rotation = Owner->rotation + initialAngle;
}

float ShootBulletComponent::GetWeaponFireRate() const
{
    return myFireRate;
}

float ShootBulletComponent::GetWeaponShootNumber() const
{
    return myShootNumber;
}
