#ifndef IBonus_H
#define IBonus_H

#include "GameObject.h"
#include "Components/CollisionHandler.h"

class IBonus : public GameObject
{

public:
	IBonus()
	{
		auto* tmp = new std::vector<sf::Vector2f>{ sf::Vector2f(-25.0f, -25.0f), sf::Vector2f(25.0f, -25.0f), sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-25.0f, 25.0f) };
		m_collisionHandler = new CollisionHandler(this, CollisionType::BonusChannel, new std::vector<CollisionType>{CollisionType::EnemyChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel, CollisionType::BonusChannel }, &m_rotation, 10, &m_position, tmp);
	}
	virtual ~IBonus() override = default;
};

#endif //IBonus_H