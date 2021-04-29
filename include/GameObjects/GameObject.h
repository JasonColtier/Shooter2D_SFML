#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

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
	sf::Vector2f offsetPos = sf::Vector2f(0, 0);//offset de position pour avoir le nez du vaisseau au milieu

	void AddComponent(Component* component);//pareil prend la classe et retourne un ptr

	virtual void OnCollision(sf::Vector2f hitPoint, GameObject* otherObject);
	
	bool isActivated = true;
	float rotation = 0;
	sf::Vector2f position = sf::Vector2f(0.f, 0.f);
	std::vector<Component*> componentList;

	CollisionHandler* collisionHandler = nullptr;
	RenderHandler* renderHandler = nullptr;


protected:

};

#endif
