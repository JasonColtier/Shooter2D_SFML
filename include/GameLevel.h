#ifndef GAMELEVEL_H
#define GAMELEVEL_H
#include <cstdint>
#include <list>
#include <SFML/Window/Window.hpp>

#include "Singleton.h"

class Component;
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

    void SpawnObject(GameObject* gameObject,sf::Vector2f& position);
    void SpawnObject(GameObject& gameObject,sf::Vector2f& position);
    
    std::vector<GameObject*> l_gameObjects;
    std::vector<Component*> l_renderComponents;

private:

    /*
     *Level assets
     */

    
    Player* player;
    //EnemySpawner*
   
    //contiendra toutes les instances de nos gameObjects
    GameLevel();
    
};
#endif
