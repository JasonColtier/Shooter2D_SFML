#ifndef IBonus_H
#define IBonus_H

#include "GameObject.h"
#include "Components/CollisionHandler.h"

class IBonus : public GameObject
{

public:
	IBonus(sf::Vector2f position, sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f)
		: GameObject(position, offsetPos, scale, rotation)
	{
		const auto Tmp = std::vector<sf::Vector2f>{ sf::Vector2f(-25.0f, -25.0f), sf::Vector2f(25.0f, -25.0f), sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-25.0f, 25.0f) };
		SetCollisionHandler(CollisionType::BonusChannel, Tmp, 10, std::vector<CollisionType>{CollisionType::EnemyChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel, CollisionType::BonusChannel });
		//m_collisionHandler = new CollisionHandler(this, CollisionType::BonusChannel, &m_rotation, &m_position, Tmp, 10, std::vector<CollisionType>{CollisionType::EnemyChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel, CollisionType::BonusChannel });
	}
	virtual ~IBonus() override = default;
};

#endif //IBonus_H