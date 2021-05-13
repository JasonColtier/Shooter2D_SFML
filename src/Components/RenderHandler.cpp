#include "Components/RenderHandler.h"

#include <map>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameWindow.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/GameObject.h"
#include "Managers/FontManager.h"


RenderHandler::RenderHandler(GameObject* t_parentGameObject, sf::Texture* t_texture,std::string t_stringKey, int t_zIndex) : parentGameObject(t_parentGameObject)
{
    AddSprite(t_texture,t_stringKey,t_zIndex);
}

sf::Sprite* RenderHandler::GetSprite(const std::string key) const
{
    auto Iterator = mapSprites.find(key);

    if (Iterator != mapSprites.end())
    {
        return Iterator->second->sprite;
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
    std::sort(sortedSprites.begin(), sortedSprites.end(), Comparator);
    
    return sprite;
}

sf::Text* RenderHandler::AddText(std::string userText, std::string key, int zIndex, sf::Vector2f pos, sf::Color color,int size)
{
    
    // Create a text
    sf::Text* text = new sf::Text(userText, *FontManager::GetFontPtr(FontManager::EnumFonts::Mandalorian));
    text->setCharacterSize(size);
    text->setFillColor(color);
    text->setPosition(pos);
    
    TextContainer* customText = new TextContainer(text,zIndex);
    mapText[key] = customText;

    sortedText.push_back(customText);

    std::sort(sortedText.begin(), sortedText.end(), Comparator);

    return customText->text;
} 

sf::Text* RenderHandler::GetText(const std::string key) const
{
    auto Iterator = mapText.find(key);

    if (Iterator != mapText.end())
    {
        return Iterator->second->text;
    }

    return nullptr;
}


void RenderHandler::RenderUpdate()
{
     //if (parentGameObject->GetCollisionHandler())
     //{
     //    std::vector<sf::Vector2f> tmp;
     //	parentGameObject->GetCollisionHandler()->GetPoints(tmp);
     //	
     //	sf::Vertex vertice[4] =
     //	{
     //		tmp[0],
     //           tmp[1],
     //           tmp[2],
     //           tmp[3]
     //       };
    
     //	GameWindow::m_window->draw(vertice, 4, sf::Quads);
     //}

    for (auto customSprite : sortedSprites)
    {
        customSprite->sprite->setRotation(parentGameObject->m_rotation);
        customSprite->sprite->setPosition(parentGameObject->m_position);
        GameWindow::m_window->draw(*customSprite->sprite);
    }

    for (auto textContainer : sortedText)
    {
        GameWindow::m_window->draw(*textContainer->text);
    }

}
