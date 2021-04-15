#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"

class RenderComponent;

namespace sf {
    class Texture;
}

class Player : public GameObject
{
public:

    //RenderComponent* renderComponent;

    Player();
    ~Player()=default;
    void Tick(int64_t deltaTime) override;

private:
    int offsetAngle = 90;//on offset l'angle de rotation de notre sprite
    float speed = 0.001f;//l'acceleration de notre vaisseau
    sf::Vector2f offsetPos = sf::Vector2f(50, 50);
    sf::Vector2f inertia = sf::Vector2f(0, 0);
    float drag = 0.001f;
    float maxVelocity = 0.00025f;
};
