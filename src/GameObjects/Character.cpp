#include "GameObjects/Character.h"


void Character::Activate(sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation)
{
    GameObject::Activate(position,offsetPos,scale,rotation);

    m_lifeComponent = new LifeComponent();
    AddComponent(m_lifeComponent);    
}

void Character::Deactivate()
{
    GameObject::Deactivate();

    m_shootComponent = nullptr;
    m_lifeComponent = nullptr;
    m_movementComponent = nullptr;
}
