#include "GameObjects/GameObject.h"

#include "GameWindow.h"
#include "Components/Component.h"
#include "Components/CollisionHandler.h"


GameObject::GameObject(sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation)
	: m_position(position)
	, m_offsetPos(offsetPos)
	, m_scale(scale)
	, m_rotation(rotation)
{
	GameWindow::GetGameLevel()->ActivateObject(*this, true);
}



void GameObject::AddComponent(Component* component)
{
	m_lComponentList.push_back(component);
	component->Owner = this;
}

void GameObject::RemoveComponent(Component* component)
{
	m_lComponentList.remove(component);
	delete component;
}

void GameObject::SetCollisionHandler(CollisionType type, const std::vector<sf::Vector2f>& points, std::vector<CollisionType> excludedCollisionType, float radius)
{
	if (m_collisionHandler != nullptr)
	{
		m_collisionHandler->Initialise(this, type, &m_rotation, &m_position, points, std::move(excludedCollisionType), radius);
	}
	else
	{
		m_collisionHandler = new CollisionHandler(this, type, std::move(excludedCollisionType), &m_rotation, radius, &m_position, points);
	}
}

void GameObject::Tick(int64_t deltaTime)
{
	for (Component* component : m_lComponentList)
	{
		component->TickComponent(deltaTime);
	}
}

//void GameObject::Activate()
//{
//	m_isActivated = true;
//}

void GameObject::Activate(const sf::Vector2f position, const sf::Vector2f offsetPos, const float scale, const float rotation)
{
	m_isActivated = true;
	m_position = position;
	m_offsetPos = offsetPos;
	m_scale = scale;
	m_rotation = rotation;

	GameWindow::GetGameLevel()->ActivateObject(*this, false);
}

void GameObject::Deactivate()
{
	if (m_isActivated)
	{
		m_isActivated = false;
	}
	for (auto* component : m_lComponentList)
	{
		delete component;
		component = nullptr;
	}
	m_lComponentList.clear();
	GameWindow::GetGameLevel()->DeactivateObject(*this);

}