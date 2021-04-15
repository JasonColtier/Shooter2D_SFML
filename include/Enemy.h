#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"

class RenderComponent;

namespace sf {
    class Texture;
}

class Enemy : public GameObject
{
public:

    Enemy();
    ~Enemy() = default;
    void Tick(int64_t deltaTime) override;
};