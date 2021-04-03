#include "Player.h"

#include <string>


Player::Player()
{
    //test rapide pour afficher une texture
    texture.loadFromFile(TextureManager::textureMap.at("Ship")), sf::IntRect(0, 0, 100, 100);
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(50.f, 50.f)); 
    sprite.setScale(sf::Vector2f(0.5f,0.5f));
}
