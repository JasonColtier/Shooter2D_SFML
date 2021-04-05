#pragma once
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "TextureManager.h"
#include "Tools/Print.h"

namespace sf {
    class RenderWindow;
}

class GameObject
{


public:
    virtual void Tick(int64_t deltaTime) = 0;
    virtual void Render(sf::RenderWindow* window) = 0;//TODO créer classe suppérieur sans rendu
    //à remplir avec les trucs communs

    //activate / deactivate
    
    GameObject();
    virtual ~GameObject();
};
