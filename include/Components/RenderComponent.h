#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include <SFML/Graphics/Sprite.hpp>

class GameObject;

namespace sf {
	class RenderWindow;
}

//TODO ne plus faire 
class RenderComponent
{
public:

	RenderComponent(GameObject* t_parentGameObject, sf::Texture* t_texture);

	//Ordre de rendu
	int zIndex = 0;

	GameObject* parentGameObject;
	sf::Texture* texture;
	sf::Sprite sprite;
	
	void RenderUpdate();
};

#endif //RENDERCOMPONENT_H
