#pragma once
#include <iostream>
#include <ostream>
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
    sf::Vector2i cursorPos;

    void StartGame();

private:
    GameLoop();
    ~GameLoop();
    
    //global parameters
    // bool useFullscreen = false;
    bool useFullscreen = true;
    float targetFPS = 60.0f;

    //temps entre chaque frame
    int64_t deltaTime; //en microsecondes !
    int updateTime = 0;//temps pour faire toutes les boucles updates avant un rendu



    GameLevel* gameLevel;
    
    //update all game objects
    void Update();
    //after all updates, one render
    void Render() const;
};
