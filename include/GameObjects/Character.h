#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include "Components/LifeComponent.h"
#include "Components/MovementComponent.h"
#include "Components/ShootComponent.h"

class Character : public GameObject
{
public:

	Character()
	{
		lifeComponent = new LifeComponent();
		AddComponent(lifeComponent);
	};
	virtual ~Character() = default;
	
	LifeComponent* lifeComponent;
};



#endif //CHARACTER_H
