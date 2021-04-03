#pragma once
#include <iostream>
#include <ostream>
#include <SFML/System/Vector2.hpp>


#include "Singleton.h"

class Player;

namespace sf
{
    class Clock;
    class RenderWindow;
}

class GameLoop : public Singleton<GameLoop>
{

    friend class Singleton<GameLoop>;

public:


private:

    GameLoop();
    ~GameLoop();
    
    //global parameters
    bool useFullscreen = false;
    float targetFPS = 120.0f;

    //temps entre chaque frame
    float deltaTime;
    int updateTime = 0;

    //notre window
    sf::RenderWindow* window;
    sf::Vector2f sizeWindow;
    
    Player* player;



    //update all game objects
    void Update();
    //after all updates, one render
    void Render();
};
