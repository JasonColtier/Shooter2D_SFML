#include "GameObjects/Bullet.h"

#include "Enemy.h"
#include "GameWindow.h"
#include "Components/CollisionHandler.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Character.h"
#include "Tools/Print.h"

#define PI 3.14159265

Bullet::Bullet()
{
    // Print::PrintLog("new bullet !");
    renderHandler = new RenderHandler(this,TextureManager::GetTexturePtr(TextureManager::Bullet),"bullet",2);

    auto sprite = renderHandler->GetSprite("bullet");

    if (sprite)
    {
        sprite->setScale(scale);
        sprite->setOrigin(10,5);
    }

    auto* tmp = new std::vector<sf::Vector2f>{ sf::Vector2f(0.0f, -4.0f), sf::Vector2f(0.0f, 9.0f), sf::Vector2f(0.0f, 4.0f), sf::Vector2f(0.0f, -9.0f) };
    collisionHandler = new CollisionHandler(this, CollisionType::PlayerProjectileChannel, new std::vector<CollisionType>({CollisionType::PlayerChannel}), &rotation, 10, &position, tmp);
}

void Bullet::Tick(int64_t deltaTime)
{
    
    if(autoDestroyDelay > 0)
    {
        timer += deltaTime;
        if(timer > autoDestroyDelay * 1000000)
        {
            Deactivate();
            return;
        }
    }
    
    
    sf::Vector2f forward(cos(rotation * PI / 180), sin(rotation * PI / 180));

    position += (forward / 1000.f * (deltaTime * 1.f)) * speed * speedMultiplier;

    if(!GameWindow::CheckIfInsideWindow(this))
    {
        Deactivate();
    }

    GameObject::Tick(deltaTime);
}

void Bullet::OnCollision(sf::Vector2f hitPoint, GameObject* otherObject)
{
    if(typeid(*otherObject) == typeid(Enemy))
    {
        auto enemy = dynamic_cast<Enemy*>(otherObject);
        enemy->lifeComponent->ModifyHealth(-damage*damageMultiplier);
        Deactivate();
    }
}
