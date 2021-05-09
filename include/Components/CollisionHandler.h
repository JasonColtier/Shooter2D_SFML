#ifndef CollisionHandler_H
#define CollisionHandler_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <cmath>

#include "Tools/Print.h"

#define PI 3.14159265

class GameObject;

enum CollisionType
{
	PlayerChannel,
	EnemyChannel,
	PlayerProjectileChannel,
	EnemyProjectileChannel,
	BonusChannel,
};

class CollisionHandler
{

public:
	CollisionHandler() = default;

	CollisionHandler(GameObject* t_owner, CollisionType t_Type, std::vector<CollisionType>* t_ExcludedCollisionType, float* t_Rotation, float t_radius, sf::Vector2f* t_Position,const std::vector<sf::Vector2f>* t_Points)
		: owner(t_owner)
		, e_Type(t_Type)
		, l_ExcludedCollisionType((t_ExcludedCollisionType))
		, position(t_Position)
		, radius(t_radius)
		, rotation(t_Rotation)
		, l_Points((t_Points))
	{
	}

	~CollisionHandler() = default;

	std::vector<sf::Vector2f> getPoints(/* prend en ref un vecteur  ou Move*/) const
	{
		//TODo réserver car on connait le nombre
		std::vector<sf::Vector2f> l_pointsInWorld;

		for (const auto point : *l_Points)
		{
			//const auto norm = sqrtf(pow(point.x, 2) + pow(point.y, 2));
			//auto t_point = sf::Vector2f((cosf(*rotation * (PI / 180)) * norm), (sinf(*rotation * (PI / 180)) * norm));

			//t_point.x *= 100;
			//t_point.x = truncf(t_point.x);
			//t_point.x /= 100;

			//t_point.y *= 100;
			//t_point.y = truncf(t_point.y);
			//t_point.y /= 100;
			const float angle = -(*rotation) * PI / 180;
			const auto xM = point.x;
			const auto yM = point.y;

			//TODO virer yM et xM
			//fonction à part avec un joli nom
			const auto x = xM * cosf(angle) - yM * sinf(angle);
			const auto y = xM * sinf(angle) + yM * cosf(angle);



			l_pointsInWorld.emplace_back(sf::Vector2f(-x + position->x, y + position->y));
		}

		return 	l_pointsInWorld;
	}

	float GetStartAbscisse() const
	{
		return (position->x - radius);
	}

	float GetEndAbscisse() const
	{
		return (position->x + radius);
	}

	GameObject* owner;
	CollisionType e_Type;
	std::vector<CollisionType>* l_ExcludedCollisionType;
	sf::Vector2f* position;
	float radius;
	float* rotation;

private:

	const std::vector<sf::Vector2f>* l_Points;
};

#endif //CollisionHandler_H
