#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "GameObject.h"
#include "Components/ShootComponent.h"
#include "Managers/InputManager.h"

class RenderHandler;

namespace sf {
    class Texture;
}

class Player : public Character
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
