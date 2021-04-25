#include "GameObjects/Bullet.h"
#include "GameWindow.h"
#include "Components/RenderComponent.h"
#include "Tools/Print.h"

#define PI 3.14159265

Bullet::Bullet(TextureManager::EnumTextures enumTextures,sf::Vector2f scale,float autoDestroyTimer)
{
    // Print::PrintLog("new bullet !");
    renderComponent = new RenderComponent(this, TextureManager::GetTexturePtr(enumTextures),2);
    renderComponent->sprite.setScale(scale);
    autoDestroyDelai = autoDestroyTimer;
}

void Bullet::Tick(int64_t deltaTime)
{

    if(autoDestroyDelai > 0)
    {
        timer += deltaTime;
        if(timer > autoDestroyDelai * 1000000)
        {
            GameWindow::GetGameLevel()->DestroyGameObject(this);
            return;
        }
    }
    
    
    sf::Vector2f forward(cos(rotation * PI / 180), sin(rotation * PI / 180));

    position += (forward / 1000.f * (deltaTime * 1.f)) * speed;

    if(!GameWindow::CheckIfInsideWindow(this))
    {
        GameWindow::GetGameLevel()->DestroyGameObject(this);
    }
}