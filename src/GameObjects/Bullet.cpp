#include "GameObjects/Bullet.h"
#include "GameWindow.h"
#include "Components/RenderComponent.h"
#include "Tools/Print.h"

#define PI 3.14159265

Bullet::Bullet()
{
    // Print::PrintLog("new bullet !");
    renderComponent = new RenderComponent(this, TextureManager::GetTexturePtr(TextureManager::Bullet),2);
    renderComponent->sprite.setScale(scale);
}

void Bullet::Tick(int64_t deltaTime)
{

    if(autoDestroyDelay > 0)
    {
        timer += deltaTime;
        if(timer > autoDestroyDelay * 1000000)
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