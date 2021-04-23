#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

class GenericBullet : public GameObject
{
public:
    
    GenericBullet();

    void Tick(int64_t deltaTime) override;

private:
    float speed = 0.5f;
    
};
#endif //BULLET_H

