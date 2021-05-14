#ifndef IBonus_H
#define IBonus_H

#include "GameObject.h"
#include "StaticData.h"
#include "Components/CollisionHandler.h"

class IBonus : public GameObject
{

public:

	void Activate(sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation) override
	{
		GameObject::Activate(position, offsetPos, scale, rotation);
		
		const auto Tmp = std::vector<sf::Vector2f>{ sf::Vector2f(-25.0f, -25.0f), sf::Vector2f(25.0f, -25.0f), sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-25.0f, 25.0f) };
		SetCollisionHandler(CollisionType::BonusChannel, Tmp, 10, std::vector<CollisionType>{CollisionType::EnemyChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel, CollisionType::BonusChannel });
	};

	void Deactivate() override
	{
		GameObject::Deactivate();
	};

	IBonus() = default;
	virtual ~IBonus() override = default;

};

#endif //IBonus_H