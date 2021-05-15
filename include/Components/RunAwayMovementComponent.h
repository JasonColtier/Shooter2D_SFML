#ifndef RUNAWAYMOVEMENTCOMPONENT_H
#define RUNAWAYMOVEMENTCOMPONENT_H

#include <SFML/System/Vector2.hpp>
#include "Components/IMovementComponent.h"

class RunAwayMovementComponent : public IMovementComponent
{
public:

	RunAwayMovementComponent() = default;

	virtual ~RunAwayMovementComponent() override = default;

	virtual void TickComponent(int64_t deltaTime = 0) override;

private:

	sf::Vector2f m_playerposition;
	sf::Vector2f m_offsetPos = sf::Vector2f(50, 50);
	sf::Vector2f m_inertia = sf::Vector2f(0, 0);
	//float distance;
	float m_randNum = 0; //pas utiliser retirer si non utiles!
	float m_drag = 0.001f;
	float m_maxVelocity = 0.00015f;
	int m_offsetAngle = 90;//on offset l'angle de rotation de notre sprite
	//float speed = 0.001f;//l'acceleration de notre vaisseau
};

#endif
