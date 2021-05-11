#ifndef  IMOVEMENTCOMPONENT_H
#define IMOVEMENTCOMPONENT_H

#include "Component.h"

class IMovementComponent : public Component
{
public:

	virtual ~IMovementComponent() override  = default;

	float m_distance = 0;
	float m_speed = 0.001f;

};

#endif // ! IMOVEMENTCOMPONENT_H