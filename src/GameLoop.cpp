﻿#include "GameLoop.h"
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

        //tant qu'on a pas atteint le nombre de fps voulu on continue les updates
        while (updateTime < (1.0 / targetFPS)*1000000)
        {
            deltaTime = clock.restart().asMicroseconds();//on utilise les microsec pour éviter de travailler avec des nombres minuscules et garder en précision
            updateTime += deltaTime;
            // Print::PrintString("max :  ",(1.0 / targetFPS)*1000000);
        
            Update();
        }

        //pour sortir du while il faut nécessairement dépasser le temps alloué pour atteindre nos FPS donc on reprend à partir de ce temps dépassé pour la prochaine update
        updateTime -= ((1.0 / targetFPS)*1000000);
        
        Print::PrintString(LOG,"last update surplus : ",updateTime);

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
    Print::PrintString(LOG,"deltaTime : ",deltaTime);
    Print::PrintString(LOG,"updateTime : ",updateTime);
}

void GameLoop::Render()
{
    Print::PrintString(WARN,"render : ");

    window->clear();

    //render loop

    window->display();
}