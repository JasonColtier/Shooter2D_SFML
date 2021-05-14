#ifndef  IMOVEMENTCOMPONENT_H
#define IMOVEMENTCOMPONENT_H

#include "Component.h"

class IMovementComponent : public Component
{
public:

	virtual ~IMovementComponent() override  = default;

	float GetSpeed()
	{
		return m_speed * m_speedModifier;
	}

	float GetMaxVelocity()
	{
		return m_maxVelocity * m_velocityModifier;
	}
	
	float m_distance = 0;
	float m_speed = 0.00001f;
	float m_speedModifier = 1.f;
	
	float m_maxVelocity = 0.00008f;
	float m_velocityModifier = 1.f;
	

};

#endif // ! IMOVEMENTCOMPONENT_H