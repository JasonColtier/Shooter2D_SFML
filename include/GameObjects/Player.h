#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "GameObject.h"
#include "Components/ShootComponent.h"
#include "Managers/InputManager.h"

class RenderHandler;

namespace sf {
	class Texture;
}

class Player : public Character
{
public:

	Player();
	~Player() override = default;
	void Tick(int64_t deltaTime) override;

	//quand on détecte un changement d'input
	void OnInputChanged(InputMapping input);

	virtual TypeId getTypeId() override { return getClassTypeId(); }
	static TypeId getClassTypeId() { return 1; }


private:

	
};

#endif
