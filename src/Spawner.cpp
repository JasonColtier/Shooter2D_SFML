#include "Spawner.h"
#include "GameLoop.h"
#include <random>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameWindow.h"
#include "GameLevel.h"
#include "Enemy.h"
#include "Components/EnemyMovementComponent.h"
#include "Components/ShotgunnerMovementComponent.h"
#include "Components/ClassicPistol.h"

Spawner::Spawner()
{
	
}

void Spawner::Tick(int64_t deltaTime)
{
	//Va initier le processus de spawn � un point al�atoire une fois la condition initiale remplie (ici toute les 2 secondes pour 1 seule type ennemie)
	Timer += deltaTime;
	if (Timer >= 2000000 && canSpawn == true)
	{
		Timer = 0;
		RandomLocation();
		canSpawn = false;
	}
}

int Spawner::ChooseSide()
{
	//va d�terminer al�atoirement de quel c�t� de l'�cran va spawn l'ennemi
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
	//le Spawn se fera � gauche de l'�cran
	case 0:
		RandomX = -1;
		RandomY = std::rand() % window->getSize().y + 1;
		break;

	//le spawn se fera � droite de l'�cran
	case 1:
		RandomX = window->getSize().x + 1;
		RandomY = std::rand() % window->getSize().y + 1;
		break;
	//le spawn se fera en haut de l'�cran
	case 2:
		RandomX = std::rand() % window->getSize().x + 1;
		RandomY = -1;
		break;

		//le spawn se fera en bas de l'�cran
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
	NewEnemy->MovementCompo = new ShotgunnerMovementComponent();
	NewEnemy->ShootComponent = new ClassicPistol();
	NewEnemy->AddComponent(NewEnemy->MovementCompo);
	NewEnemy->AddComponent(NewEnemy->ShootComponent);
	NewEnemy->rotation = 90;
}