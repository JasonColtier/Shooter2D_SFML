#include "GameLoop.h"
#include "SFML/Graphics.hpp"
#include "GameLevel.h"
#include "GameWorld.h"
#include "Managers/InputManager.h"
#include "Managers/TextureManager.h"
#include "Tools/Print.h"

GameLoop::GameLoop()
{
    Print::PrintLog("init game loop");
    if (GameWorld::useFullscreen)
    {
        GameWorld::sizeWindow.x = 1920.0f;
        GameWorld::sizeWindow.y = 1080.0f;
        GameWorld::window = new sf::RenderWindow(sf::VideoMode(GameWorld::sizeWindow.x, GameWorld::sizeWindow.y), GameWorld::gameName, sf::Style::Fullscreen);
    }
    else
    {
        GameWorld::sizeWindow.x = 1920.0f / 2;
        GameWorld::sizeWindow.y = 1080.0f / 2;
        GameWorld::window = new sf::RenderWindow(sf::VideoMode(GameWorld::sizeWindow.x, GameWorld::sizeWindow.y), GameWorld::gameName, sf::Style::Default);
    }

    GameWorld::window->setVerticalSyncEnabled(true);
}

GameLoop::~GameLoop()
{
    std::cout << "destruction";
}

void GameLoop::StartGame()
{
    Print::PrintLog("start game");
    sf::Event event;
    sf::Clock clock;

    GameWorld::LoadGameLevel();
    
    gameLevel = GameWorld::GetGameLevel();

    //la partie qui loop ! On reste dedans tant qu'on est dans le jeu
    while (GameWorld::window->isOpen())
    {

        //dupplication de code ici à cleaner
        GameWorld::cursorPos = sf::Mouse::getPosition();
        GameWorld::cursorPos.x -= GameWorld::window->getPosition().x;
        GameWorld::cursorPos.y -= GameWorld::window->getPosition().y;
        
        //keeps cursor inside of the window
        //marche à peu près mais c'est pas foufou
        int maxX = GameWorld::window->getSize().x;
        int maxY = GameWorld::window->getSize().y;
        
        int mX = sf::Mouse::getPosition(*GameWorld::window).x;
        int mY = sf::Mouse::getPosition(*GameWorld::window).y;
        
        // if (mX < 0 || mY < 0 || mX > maxX || mY > maxY)
        // {
        //     if (mX < 0)
        //         mX = 0;
        //     else if (mX > maxX)
        //         mX = maxX;
        //
        //     if (mY < 0)
        //         mY = 0;
        //     else if (mY > maxY)
        //         mY = maxY;
        //
        //     sf::Mouse::setPosition(sf::Vector2i(mX, mY), *window);
        // }
            

        //check for closing window
        while (GameWorld::window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                //TODO call destructeurs
                GameWorld::window->close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            GameWorld::window->close();

        }
        
        /*
        * updating game 
        */


        ProcessInputs();

        updateTime = 0;
        //tant qu'on a pas atteint le nombre de fps voulu on continue les updates
        while (updateTime < (1.0 / targetFPS) * 1000000 - updateSurplus)
        {
            deltaTime = clock.restart().asMicroseconds(); //on utilise les microsec pour éviter de travailler avec des nombres minuscules et garder en précision
            updateTime += deltaTime;

            Update();
        }

        //pour sortir du while il faut nécessairement dépasser le temps alloué pour atteindre nos FPS donc on reprend à partir de ce temps dépassé pour la prochaine update

        /*
        *  rendering game
        */
        Render();
        updateSurplus = updateTime - ((1.0 / targetFPS) * 1000000);

    }

}

void GameLoop::ProcessInputs()
{
    
}

void GameLoop::Update()
{
    InputManager::HandleInputs();

    gameLevel->Update(deltaTime);
    // Print::PrintLog(LOG,"updateTime : ",updateTime);
    // Print::PrintLog("deltatime : ", deltaTime);
}

void GameLoop::Render() const
{
    // Print::PrintLog(LOG,"render : ");

    GameWorld::window->clear();

    gameLevel->Render(GameWorld::window);

    GameWorld::window->display();
}
