#include "Components/RenderComponent.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "GameObjects/GameObject.h"


RenderComponent::RenderComponent(GameObject* t_parentGameObject, sf::RenderWindow* t_window, sf::Texture* t_texture) : parentGameObject(t_parentGameObject), window(t_window), texture(t_texture)
{
	sprite.setTexture(*texture);
}

void RenderComponent::RenderUpdate()
{
	sprite.setRotation(parentGameObject->rotation);
	sprite.setPosition(parentGameObject->position);
	window->draw(sprite);
}
