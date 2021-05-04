#ifndef RenderHandler_H
#define RenderHandler_H

#include <list>
#include <map>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/String.hpp>

class GameObject;

namespace sf {
	class RenderWindow;
}

//TODO ne plus faire 
class RenderHandler
{
public:

	RenderHandler(GameObject* t_parentGameObject, sf::Texture* t_texture, std::string t_stringKey, int t_zIndex);

	GameObject* parentGameObject;

	std::map<std::string,sf::Sprite*> mapSprites;

	sf::Sprite* GetSprite(const std::string key) const;

	
	//Ordre de rendu
	int zIndex = 0;

	void RenderUpdate();
};

#endif //RenderHandler_H
