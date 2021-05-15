#ifndef KAMIKAZEMOVEMENTCOMPONENT_H
#define KAMIKAZEMOVEMENTCOMPONENT_H

#include <SFML/System/Vector2.hpp>

#include "BaseEnemyMovementComponent.h"
#include "Components/IMovementComponent.h"

class KamikazeMovementComponent : public BaseEnemyMovemementComponent
{
public:

	KamikazeMovementComponent() = default;
	~KamikazeMovementComponent() override = default;

	virtual void TickComponent(int64_t deltaTime = 0) override;

};

#endif

