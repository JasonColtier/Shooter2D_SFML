#pragma once
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


#include "GameObject.h"

class Player : GameObject
{
public:
    sf::Texture texture;

    sf::Sprite sprite;

    
   Player();
};
