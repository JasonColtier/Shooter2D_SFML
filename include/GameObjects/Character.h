#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include "Components/Component.h"
#include "Components/ShootComponent.h"
#include "Components/IMovementComponent.h"

class Character : public GameObject
{
public:
	Character() = default;
	virtual ~Character() = default;

	ShootComponent* ShootComponent = nullptr;
	IMovementComponent* MovementCompo = nullptr;
};



#endif //CHARACTER_H
