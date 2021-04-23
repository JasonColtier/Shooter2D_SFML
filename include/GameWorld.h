#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <string>
#include <SFML/System/Vector2.hpp>
#include "GameLevel.h"

namespace sf {
	class RenderWindow;
}


class GameWorld
{
public:

	inline static sf::RenderWindow* window;
	inline static sf::Vector2f sizeWindow;
	inline static sf::Vector2i cursorPos;//TODO on laisse ça ici ?

	//global parameters
	inline static bool useFullscreen = false;

	inline static std::string gameName = "Shooter 2D SFML";

	static void LoadGameLevel()
	{
		GameWorld::currentGameLevel = new GameLevel();
	}

	static GameLevel* GetGameLevel()
	{
		return currentGameLevel;
	}

private:

	inline static GameLevel* currentGameLevel;
};

#endif //GAMEWORLD_H
