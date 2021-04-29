#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <list>
#include <SFML/Graphics/Sprite.hpp>
#include "Components/Component.h"
#include "Managers/TextureManager.h"

class CollisionHandler;
class RenderHandler;

namespace sf {
	class RenderWindow;
}

class GameObject
{

public:

	GameObject() = default;

	//TODO gerer la destruction de notre objet et la suppression des listes
	virtual ~GameObject() = default;

	virtual void Tick(int64_t deltaTime);

	virtual void Activate();
	virtual void Deactivate();
    sf::Vector2f offsetPos = sf::Vector2f(0, 0);//offset de position

	virtual void OnCollision(sf::Vector2f hitPoint, GameObject* otherObject);
	void AddComponent(Component* component);//ajoute un nouveau component à la liste de nos components
	void RemoveComponent(Component* component);//supprime le component
	
	//retourne le premier component trouvé de la class souhaitée
	template<class T>
	T* GetComponentOfClass()
	{
		for (auto component : componentList)
		{
			if(typeid(*component) == typeid(T))
			{
				return dynamic_cast<T*>(component);
			}
		}
		return nullptr;
	}
	
	bool isActivated = true;
	float rotation = 0;
	sf::Vector2f position = sf::Vector2f(0.f, 0.f);
	std::list<Component*> componentList;

	CollisionHandler* collisionHandler = nullptr;
	RenderHandler* renderHandler = nullptr;


protected:

};

#endif
