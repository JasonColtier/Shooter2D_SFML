#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Component.h"

enum CollisionChannel
{
	Player,
	Enemy,
	PlayerProjectile,
	EnemyProjectile,
};

class CollisionComponent : Component
{

public:

	CollisionComponent(std::vector<sf::Vector2f> t_Points, CollisionChannel t_Channel, std::vector<CollisionChannel> t_ExcludedCollisionChannel, float* t_Rotation, sf::Vector2f* t_Position)
		:l_Points(t_Points)
		, e_Channel(t_Channel)
		, l_ExcludedCollisionChannel(t_ExcludedCollisionChannel)
		, rotation(t_Rotation)
		, position(t_Position)
	{

	}


	std::vector<sf::Vector2f> getPoints()
	{
		std::vector<sf::Vector2f> l_pointsInWorld;

		for (auto point : l_Points)
		{
			l_pointsInWorld.push_back(*position + point);
		}

		return 	l_pointsInWorld;
	}




	CollisionChannel e_Channel;
	std::vector<CollisionChannel> l_ExcludedCollisionChannel;

private:

	std::vector<sf::Vector2f> l_Points;

	float* rotation;
	sf::Vector2f* position;

};

#endif //COLLISIONCOMPONENT_H
