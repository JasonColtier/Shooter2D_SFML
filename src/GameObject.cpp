#include "GameObject.h"


void GameObject::AddComponent(Component* component)
{
    componentList.push_back(component);
}

GameObject::GameObject()
{
    
}

void GameObject::Activate()
{
    isActivated = true;
}

void GameObject::Deactivate()
{
    isActivated = false;
}

GameObject::~GameObject()
{
}
