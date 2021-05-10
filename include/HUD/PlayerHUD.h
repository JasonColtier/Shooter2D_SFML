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

public:
	Player* m_player = nullptr; //set par le joueur en faisant spawner
	sf::Text m_scoreText;

private:
	void _HandleChangeScore(int score) const;

private:
	sf::Sprite* m_healthBar;
};

#endif //PlayerHUD_H