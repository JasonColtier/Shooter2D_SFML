#ifndef RUNAWAYMOVEMENTCOMPONENT_H
#define RUNAWAYMOVEMENTCOMPONENT_H

#include <SFML/System/Vector2.hpp>
#include "Components/IMovementComponent.h"
#include"Components/BaseEnemyMovementComponent.h"

class RunAwayMovementComponent : public BaseEnemyMovemementComponent
{
public:

	RunAwayMovementComponent() = default;

	virtual ~RunAwayMovementComponent() override = default;

	virtual void TickComponent(int64_t deltaTime = 0) override;

	
};

#endif
