#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite sprite;


    
   Player();
    void Tick(int64_t deltaTime) override;
    void Render(sf::RenderWindow* window) override;

private:
    int offsetAngle = 90;
    int speed = 100;
    sf::Vector2f offsetPos = sf::Vector2f(50,50);

};
