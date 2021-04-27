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

	void AddComponent(Component* component);//pareil prend la classe et retourne un ptr
	void RemoveComponent(Component* component);
	
	
	bool isActivated = true;
	float rotation = 0;
	sf::Vector2f position = sf::Vector2f(0.f, 0.f);
	std::list<Component*> componentList;

	CollisionHandler* collisionHandler = nullptr;
	RenderHandler* renderHandler = nullptr;


protected:

};

#endif
