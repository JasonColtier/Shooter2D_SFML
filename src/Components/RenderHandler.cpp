#include "Components/RenderHandler.h"

#include <map>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameWindow.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/GameObject.h"
#include "Managers/FontManager.h"


RenderHandler::RenderHandler(GameObject* parentGameObject) : m_parentGameObject(parentGameObject)
{
}

sf::Sprite* RenderHandler::AddSprite(sf::Texture* tex, std::string key, int zIndex, bool isMovable)
{
    auto* sprite = new sf::Sprite(*tex);
    auto* customSprite = new CustomContainer(std::move(key), zIndex, sprite);

    m_renderedItems.push_back(customSprite);

    // Sort using comparator function
    std::sort(m_renderedItems.begin(), m_renderedItems.end(), Comparator);

    if (isMovable)
    {
        m_MovableSprites.push_back(sprite);
    }

    return sprite;
}

sf::Text* RenderHandler::AddText(std::string userText, std::string key, int zIndex, sf::Vector2f pos, sf::Color color, int size)
{
    // Create a text
    sf::Text* text = new sf::Text(userText, *FontManager::GetFontPtr(FontManager::EnumFonts::Mandalorian));
    text->setCharacterSize(size);
    text->setFillColor(color);
    text->setPosition(pos);

    auto* customText = new CustomContainer(std::move(key), zIndex, text);

    m_renderedItems.push_back(customText);

    std::sort(m_renderedItems.begin(), m_renderedItems.end(), Comparator);

    return text;
}

void RenderHandler::RenderUpdate()
{
    // if (m_parentGameObject->m_collisionHandler)
    // {
    //     std::vector<sf::Vector2f> tmp;
    //     m_parentGameObject->m_collisionHandler->GetPoints(tmp);
    //
    //     sf::Vertex vertice[4] =
    //     {
    //         tmp[0],
    //         tmp[1],
    //         tmp[2],
    //         tmp[3]
    //     };
    //
    //     GameWindow::m_window->draw(vertice, 4, sf::Quads);
    // }

    for (auto* sprite : m_MovableSprites)
    {
    	sprite->setRotation(m_parentGameObject->m_rotation);
    	sprite->setPosition(m_parentGameObject->m_position);
    }
    
    for (auto* rendered : m_renderedItems)
    {
    	GameWindow::m_window->draw(*rendered->m_drawableItem);
    }
}
