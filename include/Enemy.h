#include <SFML/Graphics/Sprite.hpp>
#include "GameObjects/GameObject.h"


class RenderComponent;
//class Player;

namespace sf {
    class Texture;
}

class Enemy : public GameObject
{
public:

    Enemy();
    ~Enemy() override = default;
    void Tick(int64_t deltaTime) override;

private:
    //TODO Initialiser la variable Player ici
    //Player* player;
    int offsetAngle = 90;//on offset l'angle de rotation de notre sprite
    float speed = 0.001f;//l'acceleration de notre vaisseau
    sf::Vector2f offsetPos = sf::Vector2f(50, 50);
    sf::Vector2f inertia = sf::Vector2f(0, 0);
    float drag = 0.001f;
    float maxVelocity = 0.00015f;
};