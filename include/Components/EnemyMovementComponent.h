#ifndef KAMIKAZEMOVEMENTCOMPONENT_H
#define KAMIKAZEMOVEMENTCOMPONENT_H
#include "Components/IMovementComponent.h"
#include "Components/Component.h"
#include "GameObjects/GameObject.h"

class KamikazeMovementComponent : public IMovementComponent
{
public:

	KamikazeMovementComponent();

	virtual ~KamikazeMovementComponent() override = default;

	virtual void TickComponent(int64_t deltaTime = 0);


private:

	sf::Vector2f Playerposition;

	int offsetAngle = 90;//on offset l'angle de rotation de notre sprite
	float speed = 0.001f;//l'acceleration de notre vaisseau
	sf::Vector2f offsetPos = sf::Vector2f(50, 50);
	sf::Vector2f inertia = sf::Vector2f(0, 0);
	float drag = 0.001f;
	float maxVelocity = 0.00015f;
};

#endif // !ENEMYMOVEMENTCOMPONENT_H

