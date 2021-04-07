#pragma once
#include <cstdint>
#include <list>
#include <SFML/Window/Window.hpp>
#include "Singleton.h"
#include "GameObject.h"

class Player;



class GameLevel : public Singleton<GameLevel>
{
    friend class Singleton<GameLevel>;

public:

    //called by the game loop
    virtual void Update(int64_t deltaTime);
    virtual void Render(sf::RenderWindow* window);

private:

    /*
     *Level assets
     */

    //TODO une liste ou un array ?
    std::vector<GameObject*> gameObjectsList;
    
    Player* player;
    Player* player2;
    Player* player3;
    //EnemySpawner*
   
    //contiendra toutes les instances de nos gameObjects
    GameLevel();
    
};
