#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <cstdint>
#include <list>
#include "Singleton.h"
#include "GameObjects/GameObject.h"
#include <cstdarg>

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
	friend class GameObject;
	
public:
	GameLevel();
	virtual ~GameLevel() = default;

	void SpawnGameObjects();
	//called by the game loop
	virtual void Update(int64_t deltaTime);
	virtual void Render(sf::RenderWindow* window);

	template<class T = GameObject, typename ...Args>
	T* SpawnActor(Args ...args)
	{
		for (auto* object : m_lObjectsActivate)
		{
			if (!object->m_isActivated)
			{
				auto* tmp = dynamic_cast<T*>(object);
				if (tmp)
				{
					tmp->Activate(args...);
					return tmp;
				}
			}
		}
		T* newObject = new T(args...);
		m_lObjectsActivate.push_back(newObject);
		m_lObjectsWithCollision.push_back(newObject);
		return newObject;
	}

	
	void AddObjectWithCollision(CollisionHandler& object);
	void EraseObjectWithCollision(GameObject& object);
	void AddObjectRendered(RenderHandler& object);
	void EraseObjectRendered(GameObject& object);

public:

	/// <summary>
	/// Peut etre mettre en place l'intrusive liste pour optimiser un trie par insertion
	/// faire un foreach sur la liste jusqua trouver la bonne place et inserer l'objet au bonne endroit
	/// Insertion plus optimiser avec intrusive liste
	/// </summary>
	std::list<GameObject*> m_lObjectsActivate;
	std::list<GameObject*> m_lObjectsRendered;
	std::list<GameObject*> m_lObjectsWithCollision;
	std::list<GameObject*> m_lObjectsDeactivate;
	Player* m_player = nullptr;

private:
	void ActivateObject(GameObject& object, bool newObject);
	void DeactivateObject(GameObject& object);


};



#endif //GAMELEVEL_H
