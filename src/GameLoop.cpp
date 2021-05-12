#include "GameLoop.h"
#include "SFML/Graphics.hpp"
#include "GameLevel.h"
#include "GameWindow.h"
#include "Managers/InputManager.h"
#include "Tools/Print.h"

GameLoop::GameLoop()
{
	Print::PrintLog("init game loop");
	if (GameWindow::m_useFullscreen)
	{
		GameWindow::m_sizeWindow.x = 1920.0f;
		GameWindow::m_sizeWindow.y = 1080.0f;
		GameWindow::m_window = new sf::RenderWindow(sf::VideoMode(GameWindow::m_sizeWindow.x, GameWindow::m_sizeWindow.y), GameWindow::m_gameName, sf::Style::Fullscreen);
	}
	else
	{
		GameWindow::m_sizeWindow.x = 1920.0f / 2;
		GameWindow::m_sizeWindow.y = 1080.0f / 2;
		GameWindow::m_window = new sf::RenderWindow(sf::VideoMode(GameWindow::m_sizeWindow.x, GameWindow::m_sizeWindow.y), GameWindow::m_gameName, sf::Style::Default);
	}

	GameWindow::m_window->setVerticalSyncEnabled(true);
}

GameLoop::~GameLoop()
{
	std::cout << "destruction";
}

void GameLoop::StartGame()
{
	Print::PrintLog("start game");
	sf::Event Events;
	sf::Clock Clock;

	GameWindow::LoadGameLevel();

	Print::PrintLog("game level loaded");

	m_gameLevel = GameWindow::GetGameLevel();

	//la partie qui loop ! On reste dedans tant qu'on est dans le jeu
	while (GameWindow::m_window->isOpen())
	{

		//dupplication de code ici à cleaner
		GameWindow::m_cursorPos = sf::Mouse::getPosition();
		GameWindow::m_cursorPos.x -= GameWindow::m_window->getPosition().x;
		GameWindow::m_cursorPos.y -= GameWindow::m_window->getPosition().y;

		//keeps cursor inside of the m_window
		//marche à peu près mais c'est pas foufou
		int maxX = GameWindow::m_window->getSize().x;
		int maxY = GameWindow::m_window->getSize().y;

		int mX = sf::Mouse::getPosition(*GameWindow::m_window).x;
		int mY = sf::Mouse::getPosition(*GameWindow::m_window).y;

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
		while (GameWindow::m_window->pollEvent(Events))
		{
			if (Events.type == sf::Event::Closed)
			{
				//TODO call destructeurs
				GameWindow::m_window->close();
			}

			// catch the resize Events
			if (Events.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0, 0, Events.size.width, Events.size.height);
				GameWindow::m_window->setView(sf::View(visibleArea));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			GameWindow::m_window->close();
		}

		/*
		* updating game
		*/

		m_updateTime = 0;
		//tant qu'on a pas atteint le nombre de fps voulu on continue les updates
		while (m_updateTime < (1.0 / m_targetFPS) * 1000000 - m_updateSurplus)
		{
			m_deltaTime = Clock.restart().asMicroseconds(); //on utilise les microsec pour éviter de travailler avec des nombres minuscules et garder en précision
			m_updateTime += m_deltaTime;

			_Update();
		}

		//pour sortir du while il faut nécessairement dépasser le temps alloué pour atteindre nos FPS donc on reprend à partir de ce temps dépassé pour la prochaine update

		/*
		*  rendering game
		*/
		_Render();
		m_updateSurplus = m_updateTime - ((1.0 / m_targetFPS) * 1000000);
	}
}

void GameLoop::_Update()
{
	InputManager::HandleInputs();
	m_gameLevel->Update(m_deltaTime);
	// Print::PrintLog(LOG,"updateTime : ",updateTime);
	// Print::PrintLog("deltatime : ", deltaTime);
}

void GameLoop::_Render() const
{
	// Print::PrintLog(LOG,"render : ");
	GameWindow::m_window->clear();
	m_gameLevel->Render(GameWindow::m_window);
	GameWindow::m_window->display();
}
