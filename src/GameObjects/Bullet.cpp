#include "GameObjects/Bullet.h"
#include "GameWindow.h"
#include "Components/CollisionHandler.h"
#include "Components/RenderHandler.h"
#include "Tools/Print.h"

#define PI 3.14159265

Bullet::Bullet()
{
    // Print::PrintLog("new bullet !");
    renderHandler = new RenderHandler(this, TextureManager::GetTexturePtr(TextureManager::Bullet),2);
    renderHandler->sprite.setScale(scale);
    renderHandler->sprite.setOrigin(10,5);

    auto* tmp = new std::vector<sf::Vector2f>{ sf::Vector2f(0.0f, -4.0f), sf::Vector2f(0.0f, 9.0f), sf::Vector2f(0.0f, 4.0f), sf::Vector2f(0.0f, -9.0f) };
    collisionHandler = new CollisionHandler(this, CollisionType::PlayerProjectileChannel, new std::vector<CollisionType>(), &rotation, 10, &position, tmp);
}

void Bullet::Tick(int64_t deltaTime)
{

    if(autoDestroyDelay > 0)
    {
        timer += deltaTime;
        if(timer > autoDestroyDelay * 1000000)
        {
            // GameWindow::GetGameLevel()->DestroyGameObject(this);
            isActivated = false;
            return;
        }
    }
    
    
    sf::Vector2f forward(cos(rotation * PI / 180), sin(rotation * PI / 180));

    position += (forward / 1000.f * (deltaTime * 1.f)) * speed * speedMultiplier;

    if(!GameWindow::CheckIfInsideWindow(this))
    {
        // GameWindow::GetGameLevel()->DestroyGameObject(this);
        this->isActivated = false;
    }

    GameObject::Tick(deltaTime);
}