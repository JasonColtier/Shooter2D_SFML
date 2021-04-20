#include "Components/RenderComponent.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "GameObjects/GameObject.h"


RenderComponent::RenderComponent(GameObject* parentGameObject, sf::RenderWindow* window, sf::Texture* texture) : parentGameObject(parentGameObject), window(window), texture(texture)
{
    sprite.setTexture(*texture);
}

void RenderComponent::TickComponent(int64_t deltaTime)
{
    sprite.setRotation(parentGameObject->rotation);
    sprite.setPosition(parentGameObject->position);
    window->draw(sprite);
}
