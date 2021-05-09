#include <SFML/Graphics/Sprite.hpp>

#include "GameObjects/Character.h"


class RenderComponent;

namespace sf
{
    class Texture;
}

class Enemy : public Character
{
public:

    Enemy();
    ~Enemy() override = default;
    void Tick(int64_t deltaTime) override;
    void Deactivate() override;

private:
};
