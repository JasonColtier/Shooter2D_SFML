#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class RenderHandler;

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

#endif
