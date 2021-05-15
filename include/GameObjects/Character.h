#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include "Components/LifeComponent.h"
#include "Components/IMovementComponent.h"
#include "Components/ShootComponent.h"

class Character : public GameObject
{
public:

	Character() = default;
	virtual ~Character() override = default;

	virtual void Activate(sf::Vector2f position, sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f) override;

	virtual void Deactivate() override;

	void SetShootComponent(ShootComponent* shootComponent)
	{
		if (m_shootComponent != nullptr)
		{
			RemoveComponent(m_shootComponent);
		}

		AddComponent(shootComponent);
		m_shootComponent = shootComponent;
	};

	ShootComponent* GetShootComponent() const
	{
		return m_shootComponent;
	}

public:
	LifeComponent* m_lifeComponent = nullptr;
	IMovementComponent* m_movementComponent = nullptr;

private:

	ShootComponent* m_shootComponent = nullptr;
};
#endif //CHARACTER_H
