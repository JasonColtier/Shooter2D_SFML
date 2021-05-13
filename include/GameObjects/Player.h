#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "GameObject.h"
#include "Managers/InputManager.h"

class Player : public Character
{
public:

	Player(sf::Vector2f position, sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f);
	~Player() override = default;
	void Tick(int64_t deltaTime) override;

	//quand on détecte un changement d'input
	void OnInputChanged(InputMapping input) const;

	virtual TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "Player"; }
};

#endif //PLAYER_H
