#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <cstdint>
#include <list>
#include "Singleton.h"
#include "GameObjects/GameObject.h"

class Component;
class GameObject;
class CollisionManager;
class Player;
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
		for (auto* object : m_lGameObjects)
		{
			if (!object->m_isActivated)
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
		m_lGameObjects.push_back(newObject);
		m_lAbscisseGameObjects.push_back(newObject);
		return newObject;
	}

public:
	std::list<GameObject*> m_lGameObjects;
	std::list<GameObject*> m_lAbscisseGameObjects;
	Player* m_player = nullptr;
};



#endif //GAMELEVEL_H
