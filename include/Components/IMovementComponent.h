#ifndef  IMOVEMENTCOMPONENT_H
#define IMOVEMENTCOMPONENT_H
#include "Component.h"
#include "GameObjects/GameObject.h"

class IMovementComponent : public Component
{
public:

	virtual ~IMovementComponent() override  = default;

};

#endif // ! IMOVEMENTCOMPONENT_H

