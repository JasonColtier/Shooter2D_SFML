#ifndef BULLET_H
#define BULLET_H

#include "GameObjects/GameObject.h"

class Bullet : public GameObject
{
public:
    
    Bullet(TextureManager::EnumTextures enumTextures = TextureManager::Bullet,sf::Vector2f scale = sf::Vector2f(1,1),float autoDestroyTimer=0);

    void Tick(int64_t deltaTime) override;

private:
    float speed = 0.5f;
    float autoDestroyDelai = 0;
    float timer = 0;
};


#endif //BULLET_H
