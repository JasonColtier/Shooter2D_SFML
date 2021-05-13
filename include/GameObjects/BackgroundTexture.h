#ifndef BACKGROUNDTEXTURE_H
#define BACKGROUNDTEXTURE_H

#include "GameObject.h"

class BackgroundTexture : public GameObject
{
public:
	BackgroundTexture(sf::Vector2f position, sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f);
	~BackgroundTexture() = default;
};

#endif //BACKGROUNDTEXTURE_H