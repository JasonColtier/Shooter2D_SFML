#ifndef CollisionHandler_H
#define CollisionHandler_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "GameObjects/GameObject.h"

#define PI 3.14159265f

enum class CollisionType
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

	CollisionHandler(GameObject* t_owner, CollisionType t_Type, std::vector<CollisionType>* t_ExcludedCollisionType, float* t_Rotation, float t_radius, sf::Vector2f* t_Position, const std::vector<sf::Vector2f>* t_Points)
		: m_owner(t_owner)
		, m_eType(t_Type)
		, m_lExcludedCollisionType((t_ExcludedCollisionType))
		, m_position(t_Position)
		, m_radius(t_radius)
		, m_rotation(t_Rotation)
	{
		m_lPoints = t_Points;
		//std::vector<sf::Vector2f>* tmp = new std::vector<sf::Vector2f>(t_Points->size());
		//for (sf::Vector2f point : t_Points)
		//{
		//	tmp->push_back(point * owner->scale);
		//}
		//l_Points = tmp;
	}

	~CollisionHandler() = default;

	std::vector<sf::Vector2f> getPoints(/* prend en ref un vecteur  ou Move*/) const
	{
		std::vector<sf::Vector2f> l_pointsInWorld(m_lPoints->size());

		for (const auto point : *m_lPoints)
		{
			const float angle = -(*m_rotation) * PI / 180;

			//fonction à part avec un joli nom
			const auto x = point.x * cosf(angle) - point.y * sinf(angle);
			const auto y = point.x * sinf(angle) + point.y * cosf(angle);

			l_pointsInWorld.emplace_back(sf::Vector2f(-x + m_position->x, y + m_position->y));
		}
		return 	l_pointsInWorld;
	}

	float GetStartAbscisse() const
	{
		return (m_position->x - m_radius);
	}

	float GetEndAbscisse() const
	{
		return (m_position->x + m_radius);
	}

	GameObject* m_owner;
	CollisionType m_eType;
	std::vector<CollisionType>* m_lExcludedCollisionType;
	sf::Vector2f* m_position;
	float m_radius;
	float* m_rotation;

private:
	const std::vector<sf::Vector2f>* m_lPoints;
};
#endif //CollisionHandler_H
