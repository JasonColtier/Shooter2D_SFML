#include "GameObjects/Bullet.h"
#include "GameWorld.h"
#include "Components/RenderComponent.h"
#include "Tools/Print.h"

#define PI 3.14159265

Bullet::Bullet()
{
    Print::PrintLog("new bullet !");
    RenderComponent* renderComponent = new RenderComponent(this, GameWorld::window, TextureManager::GetTexturePtr(TextureManager::Bullet));
    renderComponent->sprite.setScale(sf::Vector2f(0.5f, 0.5f));

    AddComponent(renderComponent);
}

void Bullet::Tick(int64_t deltaTime)
{
    sf::Vector2f forward(cos(rotation * PI / 180), sin(rotation * PI / 180));

    position += (forward / 1000.f * (deltaTime * 1.f)) * speed;
}
