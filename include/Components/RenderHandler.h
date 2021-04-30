#ifndef RenderHandler_H
#define RenderHandler_H

#include <list>
#include <SFML/Graphics/Sprite.hpp>

class GameObject;

namespace sf {
	class RenderWindow;
}

//TODO ne plus faire 
class RenderHandler
{
public:

	RenderHandler(GameObject* t_parentGameObject, sf::Texture* t_texture, int t_zIndex);

	GameObject* parentGameObject;
	sf::Texture* texture;
	sf::Sprite sprite;

	// std::list<sf::Sprite> spriteList;
	
	//Ordre de rendu
	int zIndex = 0;

	void RenderUpdate();
};

#endif //RenderHandler_H
