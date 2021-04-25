#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H
#include <cstdint>
#include <SFML/System/Vector2.hpp>

#include "Component.h"
#include "Managers/InputManager.h"

namespace std {
    class any;
}

// typedef class InputManager InputMapping;

class MovementComponent : public Component
{
public:

    MovementComponent();
     virtual ~MovementComponent() = default;
	
    //update component
    void TickComponent(int64_t deltaTime = 0) override;

    //fired by InputManager when an input changes
    void OnInputChanged(const InputMapping input);

private:
    int offsetAngle = 90;//on offset l'angle de rotation de notre sprite
    float speed = 0.001f;//l'acceleration de notre vaisseau
    sf::Vector2f inertia = sf::Vector2f(0, 0);//conservation de la vitesse, diminue avec le temps
    float drag = 0.001f;//resistance au déplacement
    float maxVelocity = 0.00025f;//vélocité maximum

    bool moveTowardMouse = false;//est ce qu'on doit aller vers la souris ?

};

#endif
