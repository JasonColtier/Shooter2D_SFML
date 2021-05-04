#include "Components/RenderHandler.h"

#include <map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameWindow.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/GameObject.h"


RenderHandler::RenderHandler(GameObject* t_parentGameObject, sf::Texture* t_texture,std::string t_stringKey, int t_zIndex) : parentGameObject(t_parentGameObject), zIndex(t_zIndex)
{
    auto sprite = new sf::Sprite;
    sprite->setTexture(*t_texture);
    mapSprites[t_stringKey] = sprite;
}

sf::Sprite* RenderHandler::GetSprite(const std::string key) const
{
    auto iterator = mapSprites.find(key);

    if (iterator != mapSprites.end())
    {
        return iterator->second;
    }

    return nullptr;
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

    for (auto pair : mapSprites)
    {
        pair.second->setRotation(parentGameObject->rotation);
        pair.second->setPosition(parentGameObject->position);
        GameWindow::window->draw(*pair.second);
    }
}
