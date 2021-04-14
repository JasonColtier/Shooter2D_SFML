#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Components/Component.h"
#include <math.h>

#define PI 3.14159265

class GameObject;

enum CollisionChannel
{
	PlayerChannel,
	EnemyChannel,
	PlayerProjectileChannel,
	EnemyProjectileChannel,
};

class CollisionComponent : public Component
{

public:
	CollisionComponent() = default;

	CollisionComponent(std::vector<sf::Vector2f> t_Points, CollisionChannel t_Channel, std::vector<CollisionChannel> t_ExcludedCollisionChannel, float* t_Rotation, sf::Vector2f* t_Position)
		:l_Points(t_Points)
		, e_Channel(t_Channel)
		, l_ExcludedCollisionChannel(t_ExcludedCollisionChannel)
		, rotation(t_Rotation)
		, position(t_Position)
	{

	}

	virtual ~CollisionComponent() override = default;

	std::vector<sf::Vector2f> getPoints()
	{
		std::vector<sf::Vector2f> l_pointsInWorld;

		for (const auto point : l_Points)
		{
			const auto norm = sqrtf(pow(point.x, 2) + pow(point.y, 2));
			auto t_point = sf::Vector2f((cosf(*rotation * (PI / 180)) * norm), (sinf(*rotation * (PI / 180)) * norm));

			t_point.x *= 100;
			t_point.x = truncf(t_point.x);
			t_point.x /= 100;

			t_point.y *= 100;
			t_point.y = truncf(t_point.y);
			t_point.y /= 100;

			l_pointsInWorld.push_back(*position + t_point);
		}

		return 	l_pointsInWorld;
	}

	virtual void UpdateComponent() override
	{
		return;
	}

	float GetStartAbscisse() const
	{
		return (position->x - radius);
	}

	float GetEndAbscisse() const
	{
		return (position->x + radius);
	}

	virtual void OnCollision(sf::Vector2f hitPoint, GameObject* otherObject);

	CollisionChannel e_Channel;
	std::vector<CollisionChannel> l_ExcludedCollisionChannel;
	float radius;
	sf::Vector2f* position;

private:

	std::vector<sf::Vector2f> l_Points;

	float* rotation;

};

#endif //COLLISIONCOMPONENT_H
