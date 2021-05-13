#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include "Components/LifeComponent.h"
#include "Components/IMovementComponent.h"
#include "Components/ShootComponent.h"

class Character : public GameObject
{
public:
	Character(sf::Vector2f position, sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f)
		: GameObject(position, offsetPos, scale, rotation)
	{
		m_lifeComponent = new LifeComponent();
		AddComponent(m_lifeComponent);
	}

	virtual ~Character() = default;

public:
	LifeComponent* m_lifeComponent = nullptr;
	ShootComponent* m_shootComponent = nullptr;
	IMovementComponent* m_movementCompo = nullptr;
};
#endif //CHARACTER_H