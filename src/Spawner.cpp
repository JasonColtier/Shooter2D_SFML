#include "Spawner.h"
#include "GameLoop.h"
#include <random>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameWindow.h"
#include "GameLevel.h"
#include "Enemy.h"
#include "Components/KamikazeMovementComponent.h"
#include "Components/RunAwayMovementComponent.h"
#include "Components/ShotGun.h"
#include "Components/ClassicPistol.h"
#include "Components/Sniper.h"
#include "Tools/Print.h"
#include "Components/IMovementComponent.h"
#include "GameObjects/Character.h"
#include <list>
#include <iterator>

void Spawner::Tick(int64_t deltaTime)
{
	m_timer += deltaTime;
	if (m_timer >= 2000000 && m_EnemyList.size() != 2)
	{
		m_timer = 0;
		DoSpawn();
		m_canSpawn = false;
	}
}

void Spawner::DoSpawn()
{
	auto* NewEnemy = GameWindow::GetGameLevel()->SpawnActor<Enemy>(sf::Vector2f(0.f, 0.f));	
	RandomLocation(NewEnemy);
	RandomMovement(NewEnemy);
	RandomShoot(NewEnemy);
	NewEnemy->m_enemySpawner = this;
	m_EnemyList.push_back(NewEnemy);	
}

void Spawner::RandomLocation(Enemy* EnemytoSpawn)
{
	const auto* window = GameWindow::m_window;
	const auto Side = std::rand() % 4;
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
	}

	EnemytoSpawn->m_position = sf::Vector2f(RandomX, RandomY);
}

void Spawner::RandomMovement(Enemy* EnemytoSpawn)
{
	//va choisir une valeur aléatoire entre 0 et 1 (car 2 types de MovementComponents existants pour les ennemis)
	//et va attribuer au nouvel ennemi le MovementComponent correspondant
	const auto Random = std::rand() % 2;
	switch (Random)
	{
	case 0:
		EnemytoSpawn->m_movementCompo = new KamikazeMovementComponent();
		break;

	case 1:
		EnemytoSpawn->m_movementCompo = new RunAwayMovementComponent();
		break;
	}

	EnemytoSpawn->AddComponent(EnemytoSpawn->m_movementCompo);
}

void Spawner::RandomShoot(Enemy* EnemytoSpawn)
{
	//va choisir une valeur aléatoire entre 0 et 2 (car 3 types de ShootComponents existants)
	//et va attribuer au nouvel ennemi le ShootComponent correspondant
	const auto Random = std::rand() % 3;
	switch (Random)
	{
	case 0:
		EnemytoSpawn->m_shootComponent = new ClassicPistol();
		break;

	case 1:
		EnemytoSpawn->m_shootComponent = new ShotGun();
		break;

	case 2:
		EnemytoSpawn->m_shootComponent = new Sniper();
		break;
	}

	EnemytoSpawn->AddComponent(EnemytoSpawn->m_shootComponent);
}