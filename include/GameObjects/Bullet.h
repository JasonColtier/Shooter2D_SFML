﻿#ifndef BULLET_H
#define BULLET_H

#include "GameObjects/GameObject.h"

class Bullet : public GameObject
{
public:
    
    Bullet();

    void Tick(int64_t deltaTime) override;

    sf::Vector2f scale = sf::Vector2f(1,1);
    float autoDestroyDelay = 0;
    float speedMultiplier = 1.f;

private:
    float speed = 0.5f;
    float timer = 0.f;
    float damage = 1.f;
};


#endif //BULLET_H