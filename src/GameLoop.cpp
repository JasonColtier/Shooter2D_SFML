#include "GameLoop.h"
#include "SFML/Graphics.hpp"
#include "GameLevel.h"
#include "GameWindow.h"
#include "Managers/InputManager.h"
#include "Managers/TextureManager.h"
#include "Tools/Print.h"
#include "GameObjects/Player.h"
#include "GameObjects/GenericBullet.h"
#include "Managers/CollisionManager.h"

GameLoop::GameLoop()
{
	Print::PrintLog("init game loop");
	if (GameWindow::useFullscreen)
	{
		GameWindow::sizeWindow.x = 1920.0f;
		GameWindow::sizeWindow.y = 1080.0f;
		GameWindow::window = new sf::RenderWindow(sf::VideoMode(GameWindow::sizeWindow.x, GameWindow::sizeWindow.y), GameWindow::gameName, sf::Style::Fullscreen);
	}
	else
	{
		GameWindow::sizeWindow.x = 1920.0f / 2;
		GameWindow::sizeWindow.y = 1080.0f / 2;
		GameWindow::window = new sf::RenderWindow(sf::VideoMode(GameWindow::sizeWindow.x, GameWindow::sizeWindow.y), GameWindow::gameName, sf::Style::Default);
	}

	GameWindow::window->setVerticalSyncEnabled(true);
}

GameLoop::~GameLoop()
{
	std::cout << "destruction";
}

void GameLoop::StartGame()
{
	Print::PrintLog("start game");
	sf::Event events;
	sf::Clock clock;

	GameWindow::LoadGameLevel();

	gameLevel = GameWindow::GetGameLevel();

	//la partie qui loop ! On reste dedans tant qu'on est dans le jeu
	while (GameWindow::window->isOpen())
	{

		//dupplication de code ici à cleaner
		GameWindow::cursorPos = sf::Mouse::getPosition();
		GameWindow::cursorPos.x -= GameWindow::window->getPosition().x;
		GameWindow::cursorPos.y -= GameWindow::window->getPosition().y;

		//keeps cursor inside of the window
		//marche à peu près mais c'est pas foufou
		int maxX = GameWindow::window->getSize().x;
		int maxY = GameWindow::window->getSize().y;

		int mX = sf::Mouse::getPosition(*GameWindow::window).x;
		int mY = sf::Mouse::getPosition(*GameWindow::window).y;

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
		while (GameWindow::window->pollEvent(events))
		{
			if (events.type == sf::Event::Closed)
			{
				//TODO call destructeurs
				GameWindow::window->close();
			}

			// catch the resize events
			if (events.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0, 0, events.size.width, events.size.height);
				GameWindow::window->setView(sf::View(visibleArea));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			GameWindow::window->close();

		}

		/*
		* updating game
		*/

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

	GameWindow::window->clear();

	gameLevel->Render(GameWindow::window);

	GameWindow::window->display();
}
