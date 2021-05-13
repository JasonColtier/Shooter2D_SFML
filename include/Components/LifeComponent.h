#ifndef LIFECOMPONENT_H
#define LIFECOMPONENT_H

#include "Component.h"

class LifeComponent : public Component
{
public:
	LifeComponent() = default;

	void TickComponent(int64_t deltaTime) override;
	float ModifyHealth(float modification);

public:
	float m_maxHealth = 1;
	float m_currentHealth = m_maxHealth;

private:
	void _SpawnBonus();

	
	int m_chanceToSpawnBonus = 100;  // en %
};

#endif //LIFECOMPONENT_H

