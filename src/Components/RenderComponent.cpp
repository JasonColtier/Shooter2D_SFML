#include "Components/RenderComponent.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>


#include "GameWindow.h"
#include "GameObjects/GameObject.h"


RenderComponent::RenderComponent(GameObject* t_parentGameObject, sf::Texture* t_texture, int t_zIndex) : parentGameObject(t_parentGameObject), texture(t_texture), zIndex(t_zIndex)
{
	sprite.setTexture(*texture);
}

void RenderComponent::RenderUpdate()
{
	sprite.setRotation(parentGameObject->rotation);
	sprite.setPosition(parentGameObject->position);
	GameWindow::window->draw(sprite);
}
