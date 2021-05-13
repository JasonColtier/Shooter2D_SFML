#include "Components/CollisionHandler.h"
#include "GameObjects/GameObject.h"
#include "Tools/SMath.h"

void CollisionHandler::Initialise(GameObject* owner, const CollisionType type, float* rotation, sf::Vector2f* position, const std::vector<sf::Vector2f>& lPoints, std::vector<CollisionType> excludedCollisionType, const float radius)
{
	m_owner = owner;
	m_eType = type;
	m_lExcludedCollisionType = std::move(excludedCollisionType);
	m_rotation = rotation;
	m_radius = radius;
	m_position = position;
	SetPoints(lPoints);
}

void CollisionHandler::SetPoints(const std::vector<sf::Vector2f>& lPoints)
{
	const auto Size = lPoints.size();
	m_lPoints.clear();
	m_lPoints.resize(Size);
	for (size_t i = 0; i < Size; ++i)
	{
		m_lPoints[i] = lPoints[i] * m_owner->m_scale;
	}
}

void CollisionHandler::GetPoints(std::vector<sf::Vector2f>& vec) const
{
	const auto Size = m_lPoints.size();
	vec.resize(Size);

	for (size_t i = 0; i < Size; ++i)
	{
		const float Angle = -(*m_rotation) * PI / 180;

		sf::Vector2f NewPoint(m_lPoints[i]);
		SMath::RotatePoint(NewPoint, Angle);

		//je convertie la position relative � l'owner de nos points en position relative au world
		NewPoint.x = -NewPoint.x + m_position->x;
		NewPoint.y += m_position->y;
		vec[i] = NewPoint;
	}
}
