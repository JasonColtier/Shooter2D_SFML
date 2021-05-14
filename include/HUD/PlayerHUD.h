#ifndef PlayerHUD_H
#define PlayerHUD_H

#include <SFML/Graphics/Text.hpp>
#include "GameObjects/GameObject.h"

namespace sf {
	class Sprite;
}

class Player;

class PlayerHUD : public GameObject
{
public:

	PlayerHUD() =default;
	~PlayerHUD() = default;

	void Activate(sf::Vector2f position = sf::Vector2f(0.f, 0.f), sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f) override;
	void Deactivate() override
	{
		GameObject::Deactivate();
	}
	
	void Tick(int64_t deltaTime) override;

public:
	Player* m_player = nullptr; //set par le joueur en faisant spawner
	sf::Text* m_deltatimeText;
	

private:
	void _HandleChangeScore(int score) const;

private:
	sf::Sprite* m_healthBar;
};

#endif //PlayerHUD_H