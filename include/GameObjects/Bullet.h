#ifndef BULLET_H
#define BULLET_H

#include "GameObjects/GameObject.h"

class Bullet : public GameObject
{
public:
    
    Bullet();

    void Tick(int64_t deltaTime) override;

    sf::Vector2f scale = sf::Vector2f(1,1);
    float autoDestroyDelay = 0;

private:
    float speed = 0.5f;
    float timer = 0;
};


#endif //BULLET_H
