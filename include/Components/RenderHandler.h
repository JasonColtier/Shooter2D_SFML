#ifndef RenderHandler_H
#define RenderHandler_H

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>

class GameObject;

namespace sf
{
    class RenderWindow;
}

//Un container pour associer une sprite à un index
struct SpriteContainer
{
    sf::Sprite* sprite;
    int zIndex = 0;

    SpriteContainer(sf::Sprite* t_sprite, int t_zIndex) : sprite(t_sprite), zIndex(t_zIndex)
    {
    }
};

// template <typename T>
// struct CustomRenderContainer
// {
//     T* data;
//     int zIndex = 0;
//     std::string key;
//
//     CustomRenderContainer(int t_zIndex, std::string t_key): zIndex(t_zIndex), key(t_key)
//     {
//     }
//
//     T* AddData()
//     {
//         
//     }
// };

typedef std::pair<std::string, SpriteContainer*> pairKeySprite;


class RenderHandler
{
public:

    RenderHandler(GameObject* t_parentGameObject, sf::Texture* t_texture, std::string t_stringKey, int t_zIndex);

    GameObject* parentGameObject;

    std::map<std::string, SpriteContainer*> mapSprites;
    std::vector<SpriteContainer*> sortedSprites;
    sf::Sprite* RenderHandler::GetSprite(const std::string key) const;
    // auto x = new CustomRenderContainer<sf::Text>()

    sf::Sprite* AddSprite(sf::Texture* tex, std::string key, int zIndex);

    //un comparateur pour 
    static bool cmp(SpriteContainer*& a, SpriteContainer*& b)
    {
        return a->zIndex < b->zIndex;
    };


    void RenderUpdate();
};

#endif //RenderHandler_H
