#pragma once
#include <complex>
#include <ostream>
#include <SFML/System/Vector2.hpp>

class VectorTools
{
public:
    static sf::Vector2f NormaliseVector(sf::Vector2f& vec)
    {
        float length = Length(vec);
        if (length != 0)
            return sf::Vector2f(vec.x / length, vec.y / length);
        else
            return vec;
    }

    static float Length(sf::Vector2f& vec)
    {
        float len = std::sqrt((vec.x * vec.x) + (vec.y * vec.y));
        // if(len < 1)
        //     len = 1;
        return len;
    }

    static void PrintVector(sf::Vector2f& vec)
    {
        std::cout << "x : "<<vec.x<< " // y : "<<vec.y<<std::endl;
    }
};
