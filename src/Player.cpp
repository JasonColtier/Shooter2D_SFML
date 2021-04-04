#include "Player.h"


#include <random>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameLoop.h"


Player::Player()
{
    Print::PrintString("new player");
    
    //test rapide pour afficher une texture
    texture.loadFromFile(TextureManager::textureMap.at("Ship")), sf::IntRect(0, 0, 100, 100);
    sprite.setTexture(texture);
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
}

void Player::Render(sf::RenderWindow* window)
{
    window->draw(sprite);
}
