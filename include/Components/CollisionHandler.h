#ifndef CollisionHandler_H
#define CollisionHandler_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include "Components/RenderHandler.h"
#define PI 3.14159265

class GameObject;

enum CollisionType
{
	PlayerChannel,
	EnemyChannel,
	PlayerProjectileChannel,
	EnemyProjectileChannel,
};

class CollisionHandler
{

public:
	CollisionHandler() = default;

	CollisionHandler(GameObject* t_owner, CollisionType t_Type, std::vector<CollisionType>* t_ExcludedCollisionType, float* t_Rotation, float t_radius, sf::Vector2f* t_Position, std::vector<sf::Vector2f>* t_Points)
		: owner(t_owner)
		, e_Type(t_Type)
		, l_ExcludedCollisionType((t_ExcludedCollisionType))
		, position(t_Position)
		, radius(t_radius)
		, l_Points((t_Points))
		, rotation(t_Rotation)
	{

	}

	~CollisionHandler() = default;

	std::vector<sf::Vector2f> getPoints()
	{
		std::vector<sf::Vector2f> l_pointsInWorld;

		for (const auto point : *l_Points)
		{

			float angle = -(*rotation) * PI / 180;
			auto xM = point.x;
			auto yM = point.y;

			auto x = xM * cosf(angle) - yM * sinf(angle);
			auto y = xM * sinf(angle) + yM * cosf(angle);



			l_pointsInWorld.emplace_back(sf::Vector2f(-x + position->x, y + position->y));
		}

		return 	l_pointsInWorld;
		//return *l_Points;
	}

	float GetStartAbscisse() const
	{
		return (position->x - radius);
	}

	float GetEndAbscisse() const
	{
		return (position->x + radius);
	}

	void OnCollision(sf::Vector2f hitPoint, GameObject* otherObject)
	{
		return;
	}

	GameObject* owner;
	CollisionType e_Type;
	std::vector<CollisionType>* l_ExcludedCollisionType;
	sf::Vector2f* position;
	float radius;

private:

	std::vector<sf::Vector2f>* l_Points;
	float* rotation;
};

#endif //CollisionHandler_H
