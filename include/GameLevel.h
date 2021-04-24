#ifndef GAMELEVEL_H
#define GAMELEVEL_H
#include <cstdint>
#include <list>
#include <ostream>
#include <SFML/Window/Window.hpp>

#include "Singleton.h"
#include "Components/RenderComponent.h"
#include "Components/CollisionComponent.h"
#include "GameObjects/BackgroundTexture.h"
#include "GameObjects/GameObject.h"

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

	GameLevel();
	virtual ~GameLevel() = default;

	//called by the game loop
	virtual void Update(int64_t deltaTime);
	virtual void Render(sf::RenderWindow* window);

	//fonction pour destroy un game object, à finir proprement et à supprimer de toutes les listes
	virtual void DestroyGameObject(GameObject* gameObject);
	
	//template <class T>
	//T* SpawnObject()
	//{
	//	std::cout << "spawn " << std::endl;
	//	T* ptr = new T();

	//	if (dynamic_cast<GameObject*>(ptr))
	//	{
	//		std::cout << "spawn name : " << typeid(T).name() << std::endl;

	//		l_gameObjects.push_back(ptr);
	//		l_gameObjectsSRC.push_back(*ptr);

	//		for (Component* component : ptr->componentList)
	//		{
	//			if (typeid(*component) == typeid(RenderComponent))
	//			{
	//				l_renderComponents.push_back(component);
	//			}
	//			if (typeid(*component) == typeid(CollisionComponent))
	//			{
	//				l_collisionComponents.push_back(dynamic_cast<CollisionComponent*>(component));
	//			}
	//		}
	//	}
	//	return ptr;
	//}

	template<class T>
	std::enable_if_t<__is_base_of(GameObject, T), T*> SpawnActor()
	{
		for (auto* object : l_gameObjects)
		{
			if (!object->isActivated && typeid(object) == typeid(T))
			{
				object->Activate();

				//for (Component* component : objet->componentList)
				//{
				//	if (typeid(*component) == typeid(RenderComponent))
				//	{
				//		l_renderComponents.push_back(component);
				//	}
				//	if (typeid(*component) == typeid(CollisionComponent))
				//	{
				//		l_collisionComponents.push_back(dynamic_cast<CollisionComponent*>(component));
				//	}
				//}

				return dynamic_cast<T*>(object);
			}
		}

		T* newObject = new T();
		l_gameObjects.push_back(dynamic_cast<GameObject*>(newObject));

		//for (Component* component : test->componentList)
		//{
		//	if (typeid(*component) == typeid(RenderComponent))
		//	{
		//		l_renderComponents.push_back(component);
		//	}
		//	if (typeid(*component) == typeid(CollisionComponent))
		//	{
		//		l_collisionComponents.push_back(dynamic_cast<CollisionComponent*>(component));
		//	}
		//}

		return newObject;
	}

	//TODO Transformer en list
	std::list<GameObject*> l_gameObjects;

	//TODO Rajouter les composant de rendu et de collision dans la classe Gameobject et donc supprimer les deux listes ci dessous
	std::vector<Component*> l_renderComponents;
	std::vector<CollisionComponent*> l_collisionComponents;




private:

	/*
	 *Level assets
	 */

	Player* player = nullptr;
	BackgroundTexture* bgTexture = nullptr;

};


#endif //GAMELEVEL_H