#include "Components/RenderHandler.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include "GameWindow.h"
#include "GameObjects/GameObject.h"


RenderHandler::RenderHandler(GameObject* t_parentGameObject, sf::Texture* t_texture, int t_zIndex) : parentGameObject(t_parentGameObject), texture(t_texture), zIndex(t_zIndex)
{
	sprite.setTexture(*texture);
}

void RenderHandler::RenderUpdate()
{
	sprite.setRotation(parentGameObject->rotation);
	sprite.setPosition(parentGameObject->position);
	GameWindow::window->draw(sprite);

	//if (parentGameObject->collisionHandler)
	//{
	//	std::vector<sf::Vector2f> tmp = parentGameObject->collisionHandler->getPoints();
	//	//sf::VertexArray quad(sf::Quads, 3);

	//	sf::Vertex vertice[4] =
	//	{
	//		tmp[0],
	//		tmp[1],
	//		tmp[2],
	//		tmp[3]
	//	};
	//	
	//	//for (int i = 0; i < tmp.size(); ++i)
	//	//{
	//	//	quad[i] = tmp[i];
	//	//}

	//	GameWindow::window->draw(vertice, 4, sf::Quads);
	//}
}
