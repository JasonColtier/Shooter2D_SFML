#include "GameObjects/Bullets/GenericBullet.h"
#include "GameWindow.h"
#include "Components/RenderComponent.h"
#include "Tools/Print.h"

#define PI 3.14159265

GenericBullet::GenericBullet(TextureManager::EnumTextures enumTextures,sf::Vector2f scale,float autoDestroyTimer)
{
    // Print::PrintLog("new bullet !");
    renderComponent = new RenderComponent(this, TextureManager::GetTexturePtr(enumTextures),2);
    renderComponent->sprite.setScale(scale);
    autoDestroyDelay = autoDestroyTimer;
}

void GenericBullet::Tick(int64_t deltaTime)
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

    position += (forward / 1000.f * (deltaTime * 1.f)) * GetSpeed();

    if(!GameWindow::CheckIfInsideWindow(this))
    {
        GameWindow::GetGameLevel()->DestroyGameObject(this);
    }
}
