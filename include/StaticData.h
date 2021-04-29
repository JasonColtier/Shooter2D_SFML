#ifndef STATICDATA_H
#define STATICDATA_H

#include <vector>
#include <SFML/System/Vector2.hpp>

class StaticData
{
public:
	inline static const auto* ShipCollision = new std::vector<sf::Vector2f>{ sf::Vector2f(0.0f, -25.0f), sf::Vector2f(50.0f, 25.0f), sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-50.0f, 25.0f) };
};

#endif //STATICDATA_H
