#pragma once
#include <iostream>
#include <ostream>
#include <SFML/System/Vector2.hpp>

namespace sf
{
    class Clock;
    class RenderWindow;
}

class GameLoop
{
public:
    GameLoop();
    ~GameLoop();

    // //getter de singleton
    // static GameLoop& GetInstance();

private:

    //global parameters
    bool useFullscreen = false;
    float targetFPS = 42.0f;

    // //instance
    // static GameLoop m_Instance;

    //temps entre chaque frame
    float deltaTime;

    //notre window
    sf::RenderWindow* window;
    sf::Vector2f sizeWindow;
    


    //update all game objects
    void Update();
    //after all updates, one render
    void Render();
};
