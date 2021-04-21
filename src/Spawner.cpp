#include "Spawner.h"
#include "Gameloop.h"
#include <random>
#include <SFML/Graphics/RenderWindow.hpp>

Spawner::Spawner()
{
	
}



void Spawner::Tick(int64_t deltaTime)
{
	//Va initier le processus de spawn � un point al�atoire une fois la condition initiale remplie (ici toute les 2 secondes pour 1 seule type ennemie)
	Timer += deltaTime;
	if (Timer >= 2000000)
	{
		Timer = 0;
		RandomLocation();
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
	//auto window = GameLoop::GetInstance()->window;
	//int Value1 = ChooseSide();
	//float RandomX = 0;
	//float RandomY = 0;

	//switch (Value1)
	//{
	////le Spawn se fera � gauche de l'�cran
	//case 0:
	//	RandomX = -1;
	//	RandomY = std::rand() % window->getSize().y + 1;
	//	break;

	////le spawn se fera � droite de l'�cran
	//case 1:
	//	RandomX = window->getSize().x + 1;
	//	RandomY = std::rand() % window->getSize().y + 1;
	//	break;
	////le spawn se fera en haut de l'�cran
	//case 2:
	//	RandomX = std::rand() % window->getSize().x + 1;
	//	RandomY = -1;
	//	break;

	//	//le spawn se fera en bas de l'�cran
	//case 3:
	//	RandomX = std::rand() % window->getSize().x + 1;
	//	RandomY = window->getSize().y + 1;
	//	break;

	//default:
	//	break;
	//}
}

void Spawner::DoSpawn(int X, int Y)
{

}