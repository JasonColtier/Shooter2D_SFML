#include "Components/RenderHandler.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameWindow.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/GameObject.h"


RenderHandler::RenderHandler(GameObject* t_parentGameObject, sf::Texture* t_texture, int t_zIndex) : parentGameObject(t_parentGameObject), texture(t_texture), zIndex(t_zIndex)
{
    sprite.setTexture(*texture);
}

void RenderHandler::RenderUpdate()
{
    // if (parentGameObject->collisionHandler)
    // {
    // 	std::vector<sf::Vector2f> tmp = parentGameObject->collisionHandler->getPoints();
    // 	
    // 	sf::Vertex vertice[4] =
    // 	{
    // 		tmp[0],
    //            tmp[1],
    //            tmp[2],
    //            tmp[3]
    //        };
    //
    // 	GameWindow::window->draw(vertice, 4, sf::Quads);
    // }

    sprite.setRotation(parentGameObject->rotation);
    sprite.setPosition(parentGameObject->position);
    GameWindow::window->draw(sprite);
}
