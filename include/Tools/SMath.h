#ifndef SMATH_H
#define SMATH_H

#include <corecrt_math.h>
#include <type_traits>
#include <SFML/System/Vector2.hpp>

constexpr float PI = 3.14159265f;

class SMath
{
public:

	template<typename T>
	static void Pow(T& value, int power)
	{
		static_assert(std::is_arithmetic<T>::value);
		T OriginValue(value);

		for (int i = 0; i < power; ++i)
		{
			value *= OriginValue;
		}
	}

	static void RotatePoint(sf::Vector2f& point, const float angle)
	{
		const auto x = point.x * cosf(angle) - point.y * sinf(angle);
		const auto y = point.x * sinf(angle) + point.y * cosf(angle);
		point.x = x;
		point.y = y;
	}
};

#endif //SMATH_H