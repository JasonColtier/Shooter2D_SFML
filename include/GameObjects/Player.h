#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Components/ShootComponent.h"
#include "Managers/InputManager.h"

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

    //quand on détecte un changement d'input
    void OnInputChanged(InputMapping input);
private:

    ShootComponent* shootComponent;
};

#endif
