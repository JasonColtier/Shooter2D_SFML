#include "GameObjects/GenericBullet.h"
#include "GameWindow.h"
#include "Components/RenderHandler.h"


#define PI 3.14159265

GenericBullet::GenericBullet()
{
    // Print::PrintLog("new bullet !");
    renderHandler = new RenderHandler(this, TextureManager::GetTexturePtr(TextureManager::Bullet),2);
    renderHandler->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
}

void GenericBullet::Tick(int64_t deltaTime)
{
    sf::Vector2f forward(cos(rotation * PI / 180), sin(rotation * PI / 180));

    position += (forward / 1000.f * (deltaTime * 1.f)) * speed;

    if(!GameWindow::CheckIfInsideWindow(this))
    {
        GameWindow::GetGameLevel()->DestroyGameObject(this);
    }
}
