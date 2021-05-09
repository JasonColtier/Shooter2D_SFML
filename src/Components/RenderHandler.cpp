#include "Components/RenderHandler.h"

#include <map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameWindow.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/GameObject.h"


RenderHandler::RenderHandler(GameObject* t_parentGameObject, sf::Texture* t_texture,std::string t_stringKey, int t_zIndex) : parentGameObject(t_parentGameObject)
{
    AddSprite(t_texture,t_stringKey,t_zIndex);
}

sf::Sprite* RenderHandler::GetSprite(const std::string key) const
{
    auto iterator = mapSprites.find(key);

    if (iterator != mapSprites.end())
    {
        return iterator->second->sprite;
    }

    return nullptr;
}

sf::Sprite* RenderHandler::AddSprite(sf::Texture* tex,std::string key,int zIndex)
{
    auto sprite = new sf::Sprite;
    sprite->setTexture(*tex);
    SpriteContainer* customSprite = new SpriteContainer(sprite,zIndex);
    mapSprites[key] = customSprite;
    
    sortedSprites.push_back(customSprite);
    
    // Sort using comparator function
    std::sort(sortedSprites.begin(), sortedSprites.end(), cmp);
    
    return sprite;
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

    for (auto customSprite : sortedSprites)
    {
        customSprite->sprite->setRotation(parentGameObject->rotation);
        customSprite->sprite->setPosition(parentGameObject->position);
        GameWindow::window->draw(*customSprite->sprite);
    }
    
}
