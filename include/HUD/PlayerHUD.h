#ifndef PlayerHUD_H
#define PlayerHUD_H
#include "GameObjects/GameObject.h"

class Player;

class PlayerHUD : public GameObject
{
public:
    PlayerHUD();
    ~PlayerHUD() = default;

    void Tick(int64_t deltaTime) override;

private:
    Player* player;
};

#endif