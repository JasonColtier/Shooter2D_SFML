#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <cstdint>
#include <list>
#include "Singleton.h"
#include "GameObjects/BackgroundTexture.h"
#include "GameObjects/GameObject.h"
#include "Tools/Print.h"

class Component;
class GameObject;
class CollisionManager;
class Player;
//class Enemy;
class CollisionHandler;

namespace sf
{
    class RenderWindow;
}


class GameLevel
{
public:

    GameLevel();
    virtual ~GameLevel() = default;

    void SpawnGameObjects();
    
    //called by the game loop
    virtual void Update(int64_t deltaTime);
    virtual void Render(sf::RenderWindow* window);

    template<class T = GameObject>
    T* SpawnActor()
    {
        for (auto* object : l_gameObjects)
        {
            if (!object->isActivated)
            {
                auto* tmp = dynamic_cast<T*>(object);
                if (tmp)
                {
                    tmp->Activate();
                    return tmp;
                }
            }
        }

        T* newObject = new T();
        l_gameObjects.push_back(newObject);
        l_abscisseGameObjects.push_back(newObject);
        return newObject;
    }

    std::list<GameObject*> l_gameObjects;
    std::list<GameObject*> l_abscisseGameObjects;
    Player* player = nullptr;
};



#endif //GAMELEVEL_H
