#include "Spawner.h"
#include "GameLoop.h"
#include <random>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameWindow.h"
#include "GameLevel.h"
#include "Enemy.h"
#include "Components/EnemyMovementComponent.h"

Spawner::Spawner()
{
	
}

void Spawner::Tick(int64_t deltaTime)
{
	//Va initier le processus de spawn à un point aléatoire une fois la condition initiale remplie (ici toute les 2 secondes pour 1 seule type ennemie)
	Timer += deltaTime;
	if (Timer >= 2000000)
	{
		Timer = 0;
		RandomLocation();
	}
}

int Spawner::ChooseSide()
{
	//va déterminer aléatoirement de quel côté de l'écran va spawn l'ennemi
	int Value = std::rand() % 4;
	return Value;
}

void Spawner::RandomLocation()
{
	auto window = GameWindow::window;
	int Side = ChooseSide();
	float RandomX = 0;
	float RandomY = 0;

	switch (Side)
	{
	//le Spawn se fera à gauche de l'écran
	case 0:
		RandomX = -1;
		RandomY = std::rand() % window->getSize().y + 1;
		break;

	//le spawn se fera à droite de l'écran
	case 1:
		RandomX = window->getSize().x + 1;
		RandomY = std::rand() % window->getSize().y + 1;
		break;
	//le spawn se fera en haut de l'écran
	case 2:
		RandomX = std::rand() % window->getSize().x + 1;
		RandomY = -1;
		break;

		//le spawn se fera en bas de l'écran
	case 3:
		RandomX = std::rand() % window->getSize().x + 1;
		RandomY = window->getSize().y + 1;
		break;

	default:
		break;
	}

	DoSpawn(RandomX,RandomY);
}

void Spawner::DoSpawn(int X, int Y)
{ 
	Enemy* NewEnemy = GameWindow::GetGameLevel()->SpawnActor<Enemy>();
	
	NewEnemy->position = sf::Vector2f(X, Y);
	NewEnemy->AddComponent(new KamikazeMovementComponent());
	NewEnemy->rotation = 90;
}