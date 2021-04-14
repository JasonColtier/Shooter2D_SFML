#include "GameObjects/GameObject.h"


void GameObject::AddComponent(Component* component)
{
    componentList.push_back(component);
}

GameObject::GameObject()
{
    
}

void GameObject::TickComponents(int64_t deltaTime)
{
    for (Component* component : componentList)
    {
        if(component->activateTick)
        {
            component->UpdateComponent(deltaTime);
        }
    }
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
