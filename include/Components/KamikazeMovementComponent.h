#ifndef KAMIKAZEMOVEMENTCOMPONENT_H
#define KAMIKAZEMOVEMENTCOMPONENT_H

#include <SFML/System/Vector2.hpp>
#include "Components/IMovementComponent.h"

class KamikazeMovementComponent : public IMovementComponent
{
public:

	KamikazeMovementComponent() = default;
	~KamikazeMovementComponent() override = default;
	virtual void TickComponent(int64_t deltaTime = 0) override;

private:

	sf::Vector2f m_playerposition;
	sf::Vector2f m_inertia = sf::Vector2f(0, 0);
	float m_offsetAngle = 90.f;//on offset l'angle de rotation de notre sprite
	float m_drag = 0.001f;
};

#endif

