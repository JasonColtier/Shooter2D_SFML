#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Component.h"

//struct Segment
//{
//	sf::Vector2<float> 
//};

class CollisionComponent : Component
{

public:

	CollisionComponent() = default;

private:

	std::vector<sf::Vector2<float>> l_Points;
};
#endif //COLLISIONCOMPONENT_H
