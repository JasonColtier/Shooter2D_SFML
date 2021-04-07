#include "Player.h"



#include <ostream>
#include <random>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>



#include "GameLevel.h"
#include "GameLoop.h"


Player::Player()
{
    Print::PrintString("new player");
    texture = TextureManager::GetInstance()->GetTexturePtr(TextureManager::Ship);
    sprite.setTexture(*texture);    //déréférencement du pointeur pour accéder à la texture
    sprite.setPosition(sf::Vector2f(300.f, 300.f));
    sprite.setOrigin(sf::Vector2f(50.f, 50.f));
    sprite.setScale(sf::Vector2f(0.5f, 0.5f));

    //offset pour que le nez du vaisseau soit vers la souris
    offsetPos.x = 100*0.5f/2;
    offsetPos.y = 100*0.5f/2;
}

void Player::Tick(int64_t deltaTime)
{
    auto mousePos = GameLoop::GetInstance()->cursorPos;
    auto pos = sprite.getPosition();

    //distance vers la souris
    float deltaPosX = mousePos.x - (pos.x + offsetPos.x);
    float deltaPosY = mousePos.y - (pos.y + offsetPos.y);

    //rotation pour se tourner vers la souris
    float rot = std::atan2(deltaPosY,deltaPosX) * 180 / std::_Pi;
    sprite.setRotation(rot + offsetAngle);

    //update de la position
    pos.x += deltaPosX/(10000 * speed) * deltaTime;
    pos.y += deltaPosY/(10000 * speed) * deltaTime;
    sprite.setPosition(pos);

    // Print::PrintString(pos.x);
    // Print::PrintString(pos.y);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        Print::PrintString("delete player");
        GameLevel::GetInstance()->gameObjectsList.erase(std::remove(GameLevel::GetInstance()->gameObjectsList.begin(), GameLevel::GetInstance()->gameObjectsList.end(), this), GameLevel::GetInstance()->gameObjectsList.end());
        delete this;
        
    }
    
}

void Player::Render(sf::RenderWindow* window)
{
    window->draw(sprite);
}
