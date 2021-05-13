#ifndef IBonus_H
#define IBonus_H

#include "GameObject.h"
#include "StaticData.h"
#include "Components/CollisionHandler.h"

class IBonus : public GameObject
{

public:
	IBonus(sf::Vector2f position = sf::Vector2f(0.f, 0.f), sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f)
		: GameObject(position, offsetPos, scale, rotation)
	{
		m_collisionHandler = new CollisionHandler(this, CollisionType::BonusChannel, std::vector<CollisionType>{CollisionType::EnemyChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel, CollisionType::BonusChannel }, & m_rotation, 10, & m_position, StaticData::BonusCollision);
	}
	virtual ~IBonus() override = default;
};

#endif //IBonus_H