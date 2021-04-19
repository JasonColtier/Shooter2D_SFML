#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"

class RenderComponent;

namespace sf {
    class Texture;
}

class Player : public GameObject
{
public:

    Player();
    ~Player()=default;
    void Tick(int64_t deltaTime) override;

private:
    
};
