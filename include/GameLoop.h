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
    static GameLoop& GetInstance();

private:

    bool useFullscreen = false;
    float targetFPS = 36.0f;
    
    bool updateFinished = false;
    static GameLoop m_Instance;
    float deltaTime;
    sf::RenderWindow* window;
    sf::Vector2f sizeWindow;
    

    GameLoop();
    ~GameLoop();

    //Looping part
    void Loop();

    //update all game objects
    void Update();
    //after all updates, one render
    void Render();
};
