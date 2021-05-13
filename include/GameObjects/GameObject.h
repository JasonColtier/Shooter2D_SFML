#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <list>
#include <SFML/Graphics/Sprite.hpp>
#include "Components/Component.h"
#include "Managers/TextureManager.h"

class CollisionHandler;
class RenderHandler;

using TypeId = std::string;

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

	void AddComponent(Component* component);//ajoute un nouveau component à la liste de nos components
	void RemoveComponent(Component* component);//supprime le component

	//retourne le premier component trouvé de la class souhaitée
	template<class T>
	T* GetComponentOfClass()
	{
		for (auto component : m_lComponentList)
		{
			auto* Tmp = dynamic_cast<T*>(component);
			if (Tmp != nullptr)
			{
				return Tmp;
			}
		}
		return nullptr;
	}

	virtual TypeId GetTypeId() { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "GameObject"; }

public:
	bool m_isActivated = true;
	float m_rotation = 0;
	float m_scale = 0.5f;
	sf::Vector2f m_position = sf::Vector2f(0.f, 0.f);
	sf::Vector2f m_offsetPos = sf::Vector2f(0, 0);//offset de position

	std::list<Component*> m_lComponentList;
	CollisionHandler* m_collisionHandler = nullptr;
	RenderHandler* m_renderHandler = nullptr;

};

#endif //GAMEOBJECT_H