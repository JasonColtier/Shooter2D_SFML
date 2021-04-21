#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics/Sprite.hpp>
#include "Components/Component.h"
#include "Managers/TextureManager.h"

class CollisionComponent;
class RenderComponent;

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

	void AddComponent(Component* component);//pareil prend la classe et retourne un ptr

	bool isActivated = true;
	float rotation = 0;
	sf::Vector2f position = sf::Vector2f(0.f, 0.f);
	std::vector<Component*> componentList;

	CollisionComponent* collisionComponent = nullptr;
	RenderComponent* renderComponent = nullptr;


protected:

};

#endif //GAMEOBJECT_H