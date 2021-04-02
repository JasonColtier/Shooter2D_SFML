#include "GameLoop.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <ostream>

#include "Tools/Print.h"


// GameLoop GameLoop::m_Instance = GameLoop();

GameLoop::GameLoop()
{
    std::cout << "init Game loop" << std::endl;
    if (useFullscreen)
    {
        sizeWindow.x = 1920.0f;
        sizeWindow.y = 1080.0f;
        window = new sf::RenderWindow(sf::VideoMode(this->sizeWindow.x, this->sizeWindow.y), "Shooter 2D SFML", sf::Style::Fullscreen);
    }
    else
    {
        sizeWindow.x = 1920.0f / 2;
        sizeWindow.y = 1080.0f / 2;
        window = new sf::RenderWindow(sf::VideoMode(this->sizeWindow.x, this->sizeWindow.y), "Shooter 2D SFML", sf::Style::Default);
    }

    window->setVerticalSyncEnabled(true);

    sf::Event event;
    sf::Clock clock;

    //la partie qui loop ! On reste dedans tant qu'on est dans le jeu
    while (window->isOpen())
    {
        //check for closing window
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window->close();
        }

        /*
         * updating game 
         */

        float updateTime = 0;//pas reset, on garde le temps de frame d'avant

        //tant qu'on a pas atteint le nombre de fps voulu on continue les updates
        while (updateTime < 1.0 / targetFPS)
        {
            deltaTime = clock.restart().asSeconds();
            Update();
            updateTime += deltaTime;
            // std::cout << "updateTime : " << updateTime << std::endl;
        }

        /*
         *  rendering game
         */
        Render();
    }
}

GameLoop::~GameLoop()
{
    std::cout << "destruction";
}

// GameLoop& GameLoop::GetInstance()
// {
//     return m_Instance;
// }

void GameLoop::Update()
{
    std::cout << "deltaTime : " << deltaTime << std::endl;
}

void GameLoop::Render()
{
    std::cout << "render" << std::endl;
    window->clear();

    //render loop

    window->display();
}
