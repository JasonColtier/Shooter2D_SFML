#include "Spawner.h"
#include "GameLoop.h"
#include <random>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameWindow.h"
#include "GameLevel.h"
#include "Enemy.h"
#include "Components/EnemyMovementComponent.h"
#include "Components/ShotgunnerMovementComponent.h"
#include "Components/ShotGun.h"

void Spawner::Tick(int64_t deltaTime)
{
	//Va initier le processus de spawn à un point aléatoire une fois la condition initiale remplie (ici toute les 2 secondes pour 1 seule type ennemie)
	m_timer += deltaTime;
	if (m_timer >= 2000000 && m_canSpawn == true)
	{
		m_timer = 0;
		RandomLocation();
		m_canSpawn = false;
	}
}

int Spawner::ChooseSide()
{
	//va déterminer aléatoirement de quel côté de l'écran va spawn l'ennemi
	const auto Value = std::rand() % 4;
	return Value;
}

void Spawner::RandomLocation()
{
	const auto* window = GameWindow::m_window;
	const auto Side = ChooseSide();
	auto RandomX = 0;
	auto RandomY = 0;

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

	DoSpawn(RandomX, RandomY);
}

void Spawner::DoSpawn(const int X, const int Y)
{
	auto* NewEnemy = GameWindow::GetGameLevel()->SpawnActor<Enemy>(sf::Vector2f(static_cast<float>(X), static_cast<float>(Y)));

	//NewEnemy->m_position = sf::Vector2f(static_cast<float>(X), static_cast<float>(Y));
	NewEnemy->m_movementCompo = new ShotgunnerMovementComponent();
	NewEnemy->m_shootComponent = new ShotGun();
	NewEnemy->AddComponent(NewEnemy->m_movementCompo);
	NewEnemy->AddComponent(NewEnemy->m_shootComponent);
	NewEnemy->m_rotation = 90;
}