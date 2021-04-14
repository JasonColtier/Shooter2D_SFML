#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

class Bullet : public GameObject
{
public:
    Bullet();

    void Tick(int64_t deltaTime) override;
    
};
#endif

