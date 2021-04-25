#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include <SFML/Graphics/Sprite.hpp>

class GameObject;

namespace sf {
	class RenderWindow;
}

//TODO ne plus faire 
class RenderHandler
{
public:

	RenderHandler(GameObject* t_parentGameObject, sf::RenderWindow* t_window, sf::Texture* t_texture);

	//Ordre de rendu
	int zIndex = 0;

	GameObject* parentGameObject;
	sf::RenderWindow* window;
	sf::Texture* texture;
	sf::Sprite sprite;

	void RenderUpdate();
};

#endif //RENDERCOMPONENT_H
