#ifndef LIFECOMPONENT_H
#define LIFECOMPONENT_H

#include "Component.h"

class LifeComponent : public Component
{
public:
	LifeComponent() = default;

	void TickComponent(int64_t deltaTime) override;
	void ModifyHealth(float modification);

public:
	float m_maxHealth = 1;
	float m_currentHealth = m_maxHealth;

private:

	
};

#endif //LIFECOMPONENT_H

