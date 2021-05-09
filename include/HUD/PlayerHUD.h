#ifndef PlayerHUD_H
#define PlayerHUD_H
#include <SFML/Graphics/Text.hpp>

#include "GameObjects/GameObject.h"

class Player;

class PlayerHUD : public GameObject
{
public:
    PlayerHUD();
    ~PlayerHUD() = default;

    void Tick(int64_t deltaTime) override;

    Player* player = nullptr; //set par le joueur en faisant spawner

    sf::Text ScoreText;

private:
    sf::Sprite* healthBar;
};

#endif