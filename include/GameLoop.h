#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <iostream>
#include <ostream>
#include <string>
#include <SFML/System/Vector2.hpp>

#include "Singleton.h"

class GameLevel;

namespace sf
{
    class Clock;
    class RenderWindow;
}

class GameLoop : public Singleton<GameLoop>
{

    friend class Singleton<GameLoop>;

public:
    //notre window
    sf::RenderWindow* window;
    sf::Vector2f sizeWindow;
    sf::Vector2i cursorPos;//TODO on laisse ça ici ?

    void StartGame();

private:
    GameLoop();
    ~GameLoop();
    
    //global parameters
    bool useFullscreen = false;
    float targetFPS = 60.0f;
    std::string gameName = "Shooter 2D SFML";

    //temps entre chaque frame
    int64_t deltaTime; //en microsecondes !
    int updateTime = 0;//temps pour faire toutes les boucles updates avant un rendu
    int updateSurplus = 0;//temps pour faire toutes les boucles updates avant un rendu



    GameLevel* gameLevel;

    void ProcessInputs();
    //update all game objects
    void Update();
    //after all updates, one render
    void Render() const;
};
#endif
