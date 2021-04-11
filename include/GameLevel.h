﻿#include <cstdint>
#include <list>
#include <SFML/Window/Window.hpp>
#include "Singleton.h"

class RenderedGameObject;
class GameObject;

namespace sf {
    class RenderWindow;
}

class Player;



class GameLevel : public Singleton<GameLevel>
{
    friend class Singleton<GameLevel>;

public:

    //called by the game loop
    virtual void Update(int64_t deltaTime);
    virtual void Render(sf::RenderWindow* window);

    void SpawnObject(GameObject* gameObject);
    
    std::vector<GameObject*> gameObjectsList;
    std::vector<RenderedGameObject*> renderedList;

private:

    /*
     *Level assets
     */

    
    Player* player;
    //EnemySpawner*
   
    //contiendra toutes les instances de nos gameObjects
    GameLevel();
    
};
