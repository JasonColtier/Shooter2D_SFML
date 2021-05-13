#ifndef CollisionHandler_H
#define CollisionHandler_H

#include <vector>
#include <SFML/System/Vector2.hpp>

class GameObject;

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

	CollisionHandler(GameObject* owner, const CollisionType type, std::vector<CollisionType> excludedCollisionType, float* rotation, const float radius, sf::Vector2f* position, const std::vector<sf::Vector2f>& lPoints)
		: m_owner(owner)
		, m_eType(type)
		, m_lExcludedCollisionType(std::move(excludedCollisionType))
		, m_position(position)
		, m_radius(radius)
		, m_rotation(rotation)
	{
		SetPoints(lPoints);
	}

	~CollisionHandler() = default;

	void Initialise(GameObject* owner, CollisionType type, float* rotation, sf::Vector2f* position, const std::vector<sf::Vector2f>& lPoints, std::vector<CollisionType> excludedCollisionType = std::vector<CollisionType>(), float radius = 0);

	void SetPoints(const std::vector<sf::Vector2f>& lPoints);

	void GetPoints(std::vector<sf::Vector2f>& vec) const;

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
	std::vector<CollisionType> m_lExcludedCollisionType;
	sf::Vector2f* m_position;
	float m_radius;
	float* m_rotation;

private:

	std::vector<sf::Vector2f> m_lPoints;
};

#endif //CollisionHandler_H