#include "GameLoop.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <ostream>


GameLoop GameLoop::m_Instance = GameLoop();

GameLoop::GameLoop()
{
    std::cout << "init Game loop" << std::endl;
    if (useFullscreen)
    {
        this->sizeWindow.x = 1920.0f;
        this->sizeWindow.y = 1080.0f;
        this->window = new sf::RenderWindow(sf::VideoMode(this->sizeWindow.x, this->sizeWindow.y), "Shooter 2D SFML",
                                            sf::Style::Fullscreen);
    }
    else
    {
        this->sizeWindow.x = 1920.0f / 2;
        this->sizeWindow.y = 1080.0f / 2;
        this->window = new sf::RenderWindow(sf::VideoMode(this->sizeWindow.x, this->sizeWindow.y), "Shooter 2D SFML",
                                            sf::Style::Default);
    }

    this->window->setVerticalSyncEnabled(true);

    Loop();
}

GameLoop::~GameLoop()
{
    std::cout << "destruction";
}

GameLoop& GameLoop::GetInstance()
{
    return m_Instance;
}

void GameLoop::Loop()
{
    sf::Event event;
    sf::Clock clock;

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

        //updating game 
        float updateTime = 0;  
        while (updateTime < 1.0/targetFPS)
        {
            deltaTime = clock.restart().asSeconds();
            Update();
            updateTime += deltaTime;
            std::cout << "updateTime : " << updateTime << std::endl;
        }

        Render();
    }
}

void GameLoop::Update()
{

    std::cout << "Update" << std::endl;
    std::cout << "deltaTime : " << deltaTime << std::endl;
}

void GameLoop::Render()
{
    std::cout << "render" << std::endl;
    this->window->clear();

    //render loop
    
    this->window->display();
}
