#ifndef SHOTGUNNERMOVEMENTCOMPONENT_H
#define SHOTGUNNERMOVEMENTCOMPONENT_H

#include "Components/IMovementComponent.h"
#include"Components/BaseEnemyMovementComponent.h"
#include "GameObjects/GameObject.h"

class RunAwayMovementComponent : public BaseEnemyMovemementComponent
{
public:

	RunAwayMovementComponent() = default;

	virtual ~RunAwayMovementComponent() override = default;

	virtual void TickComponent(int64_t deltaTime = 0) override;

	
};

#endif // !SHOTGUNNERMOVEMENTCOMPONENT_H
