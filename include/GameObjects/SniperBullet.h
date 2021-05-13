#ifndef SNIPERBULLET_H
#define SNIPERBULLET_H

#include "Bullet.h"

class SniperBullet : public Bullet
{
public:
    SniperBullet(sf::Vector2f position, sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f);

    //void OnCollision(sf::Vector2f hitPoint, GameObject* otherObject) override;

};

#endif //SNIPERBULLET_H
