#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <cstdint>
#include <list>
#include <SFML/Window/Window.hpp>

#include "Singleton.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/BackgroundTexture.h"
#include "Components/RenderHandler.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/GameObject.h"

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

	//called by the game loop
	virtual void Update(int64_t deltaTime);
	virtual void Render(sf::RenderWindow* window);

	virtual void DestroyGameObject(GameObject* gameObject);
	template<class T>
	std::enable_if_t<__is_base_of(GameObject, T), T*> SpawnActor()
	{
		for (auto* object : l_gameObjects)
		{
			if (!object->isActivated && typeid(object) == typeid(T))
			{
				object->Activate();
				return dynamic_cast<T*>(object);
			}
		}

		GameObject* newObject = new T();
		l_gameObjects.push_back(newObject);
		l_abscisseGameObjects.push_back(newObject);
		return dynamic_cast<T*>(newObject);
	}

	std::list<GameObject*> l_gameObjects;
	BackgroundTexture* bgTexture = nullptr;
	std::list<GameObject*> l_abscisseGameObjects;
	Player* player;

};


#endif //GAMELEVEL_H