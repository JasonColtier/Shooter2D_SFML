#pragma once
#include <cstdint>
#include <SFML/System/Vector2.hpp>


#include "Component.h"

namespace std {
    class any;
}

class MovementComponent : public Component
{
public:

    MovementComponent();

    //check inputs
    void TickComponent(int64_t deltaTime) override;
    void OnInputForward(std::any i);

private:
    int offsetAngle = 90;//on offset l'angle de rotation de notre sprite
    float speed = 0.001f;//l'acceleration de notre vaisseau
    sf::Vector2f offsetPos = sf::Vector2f(50, 50);
    sf::Vector2f inertia = sf::Vector2f(0, 0);
    float drag = 0.001f;
    float maxVelocity = 0.00025f;

    bool moveTowardMouse = false;

};
