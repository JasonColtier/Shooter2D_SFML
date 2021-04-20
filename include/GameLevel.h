#ifndef GAMELEVEL_H
#define GAMELEVEL_H
#include <cstdint>
#include <list>
#include <ostream>
#include <SFML/Window/Window.hpp>

#include "Singleton.h"
#include "Components/RenderComponent.h"
#include "Components/CollisionComponent.h"

class Component;
class GameObject;
class CollisionManager;
class Player;
//class Enemy;
class CollisionComponent;

namespace sf
{
    class RenderWindow;
}



class GameLevel
{

public:

    //called by the game loop
    virtual void Update(int64_t deltaTime);
    virtual void Render(sf::RenderWindow* window);


    template <class T>
    T* SpawnObject()
    {
        std::cout << "spawn "<<std::endl;
        T* ptr = new T();
        
        if (dynamic_cast<GameObject*>(ptr))
        {
            std::cout << "spawn name : "<<typeid(T).name() << std::endl;

            l_gameObjects.push_back(ptr);
            l_gameObjectsSRC.push_back(*ptr);

            for (Component* component : ptr->componentList)
            {
                if (typeid(*component) == typeid(RenderComponent))
                {
                    l_renderComponents.push_back(component);
                }
                if (typeid(*component) == typeid(CollisionComponent))
                {
                    l_collisionComponents.push_back(dynamic_cast<CollisionComponent*>(component));
                }
            }
        }
        return ptr;
    }


    std::vector<GameObject*> l_gameObjects;
    std::vector<GameObject> l_gameObjectsSRC;
    std::vector<Component*> l_renderComponents;
    std::vector<CollisionComponent*> l_collisionComponents;



    ~GameLevel() = default;
    GameLevel();

private:

    /*
     *Level assets
     */


    Player* player;
    //EnemySpawner*
    CollisionManager* collisionManager;
    //contiendra toutes les instances de nos gameObjects
};


#endif
