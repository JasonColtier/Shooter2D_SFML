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


struct CustomContainer
{
    int zIndex = 0;
};

//Un container pour associer une sprite à un index
struct SpriteContainer : CustomContainer
{
    sf::Sprite* sprite;

    SpriteContainer(sf::Sprite* t_sprite, int t_zIndex) : sprite(t_sprite)
    {
        zIndex = t_zIndex;
    }
};

struct TextContainer : CustomContainer
{
    sf::Text* text;

    TextContainer(sf::Text* t_text, int t_zIndex) : text(t_text)
    {
        zIndex = t_zIndex;
    }
};


typedef std::pair<std::string, SpriteContainer*> pairKeySprite;


class RenderHandler
{
public:

    RenderHandler(GameObject* t_parentGameObject, sf::Texture* t_texture, std::string t_stringKey, int t_zIndex);

    GameObject* parentGameObject;

    std::map<std::string, SpriteContainer*> mapSprites;
    std::vector<SpriteContainer*> sortedSprites;


    std::map<std::string, TextContainer*> mapText;
    std::vector<TextContainer*> sortedText;
    
    
    sf::Sprite* AddSprite(sf::Texture* tex, std::string key, int zIndex);
    sf::Sprite* GetSprite(std::string key) const;

    sf::Text* AddText(std::string* userText,std::string key,int zIndex,sf::Vector2f pos = sf::Vector2f(0,0),sf::Color color = sf::Color::White,int size = 30);
    sf::Text* GetText(std::string key) const;

    
    //un comparateur pour 
    static bool Comparator(CustomContainer* a, CustomContainer* b)
    {
        return a->zIndex < b->zIndex;
    };


    void RenderUpdate();
};

#endif //RenderHandler_H
