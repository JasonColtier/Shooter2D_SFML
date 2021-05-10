#ifndef SHOTGUNNERMOVEMENTCOMPONENT_H
#define SHOTGUNNERMOVEMENTCOMPONENT_H
#include "Components/IMovementComponent.h"
#include "Components/Component.h"
#include "GameObjects/GameObject.h"

class ShotgunnerMovementComponent : public IMovementComponent
{
public:

	ShotgunnerMovementComponent();

	virtual ~ShotgunnerMovementComponent() override = default;

	virtual void TickComponent(int64_t deltaTime = 0);

private :

	sf::Vector2f Playerposition;

	//float distance;
	float randNum = 0;

	int offsetAngle = 90;//on offset l'angle de rotation de notre sprite
	//float speed = 0.001f;//l'acceleration de notre vaisseau
	sf::Vector2f offsetPos = sf::Vector2f(50, 50);
	sf::Vector2f inertia = sf::Vector2f(0, 0);
	float drag = 0.001f;
	float maxVelocity = 0.00015f;
};

#endif // !SHOTGUNNERMOVEMENTCOMPONENT_H
