#include <SFML/Graphics/Sprite.hpp>
#include "GameObjects/GameObject.h"
#include "GameObjects/Character.h"


class RenderComponent;

namespace sf {
    class Texture;
}

class Enemy : public Character
{
public:

    Enemy();
    ~Enemy() override = default;
    void Tick(int64_t deltaTime) override;

private:
    
};