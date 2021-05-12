#include "GameObjects/GameObject.h"


void GameObject::AddComponent(Component* component)
{
	m_lComponentList.push_back(component);
	component->Owner = this;
}

void GameObject::RemoveComponent(Component* component)
{
	m_lComponentList.remove(component);
}

void GameObject::Tick(int64_t deltaTime)
{
	for (Component* component : m_lComponentList)
	{
		component->TickComponent(deltaTime);
	}
}

void GameObject::Activate()
{
	m_isActivated = true;
}

void GameObject::Deactivate()
{
	if (m_isActivated)
	{
		m_isActivated = false;
	}
}