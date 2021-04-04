#include "GameLoop.h"
#include "SFML/Graphics.hpp"
#include "GameLevel.h"


GameLoop::GameLoop()
{
    Print::PrintString("init game loop");
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
}

GameLoop::~GameLoop()
{
    std::cout << "destruction";
}

void GameLoop::StartGame()
{
    sf::Event event;
    sf::Clock clock;

    gameLevel = gameLevel->GetInstance();

    //la partie qui loop ! On reste dedans tant qu'on est dans le jeu
    while (window->isOpen())
    {

        //keeps cursor inside of the window
        //marche à peu près mais c'est pas foufou
        int maxX = window->getSize().x;
        int maxY = window->getSize().y;

        int mX = sf::Mouse::getPosition(*window).x;
        int mY = sf::Mouse::getPosition(*window).y;

        if (mX < 0 || mY < 0 || mX > maxX || mY > maxY)
        {
            if (mX < 0)
                mX = 0;
            else if (mX > maxX)
                mX = maxX;

            if (mY < 0)
                mY = 0;
            else if (mY > maxY)
                mY = maxY;

            sf::Mouse::setPosition(sf::Vector2i(mX, mY), *window);
        }
            


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

        cursorPos = sf::Mouse::getPosition();
        cursorPos.x -= window->getPosition().x;
        cursorPos.y -= window->getPosition().y;

        //tant qu'on a pas atteint le nombre de fps voulu on continue les updates
        while (updateTime < (1.0 / targetFPS) * 1000000)
        {


            deltaTime = clock.restart().asMicroseconds(); //on utilise les microsec pour éviter de travailler avec des nombres minuscules et garder en précision
            updateTime += deltaTime;

            Update();
        }

        //pour sortir du while il faut nécessairement dépasser le temps alloué pour atteindre nos FPS donc on reprend à partir de ce temps dépassé pour la prochaine update
        updateTime -= ((1.0 / targetFPS) * 1000000);

        // Print::PrintString(LOG,"last update surplus : ",updateTime);

        /*
        *  rendering game
        */
        Render();
    }
}

void GameLoop::Update()
{
    // Print::PrintString(LOG,"updateTime : ",updateTime);
    gameLevel->Update(deltaTime);
}

void GameLoop::Render() const
{
    // Print::PrintString(LOG,"render : ");

    window->clear();

    gameLevel->Render(window);

    window->display();
}
