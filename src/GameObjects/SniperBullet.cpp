#include "GameObjects/SniperBullet.h"

#include "Enemy.h"
#include "Components/RenderHandler.h"

SniperBullet::SniperBullet()
{
    damage *= 3;
    speed *= 3;
    renderHandler->sprite.setScale(sf::Vector2f(10,10));
}

void SniperBullet::OnCollision(sf::Vector2f hitPoint, GameObject* otherObject)
{
    if(typeid(*otherObject) == typeid(Enemy))
    {
        auto enemy = dynamic_cast<Enemy*>(otherObject);
        enemy->lifeComponent->ModifyHealth(-damage*damageMultiplier);
    }
}
