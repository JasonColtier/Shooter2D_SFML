#include "Components/EnemyMovementComponent.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameLevel.h"
#include "GameLoop.h"
#include "GameWindow.h"
#include "Components/IMovementComponent.h"
#include "Components/Component.h"
#include "GameObjects/Player.h"
#include "Components/RenderHandler.h"
#include "Tools/VectorTools.h"
#include <ostream>
#include <random>
#include <valarray>
#include <cmath>
#include "Tools/Print.h"


KamikazeMovementComponent::KamikazeMovementComponent()
{

}

void KamikazeMovementComponent::TickComponent(int64_t deltaTime)
{

	////TODO insérer la récup de la Position du Player ici
	auto level = GameWindow::GetGameLevel();
	Playerposition = level->player->position;
	auto pos = Owner->position;

	//calcul de la disance avec le player
	float deltaPosX = Playerposition.x - (pos.x + Owner->offsetPos.x);
	float deltaPosY = Playerposition.y - (pos.y + Owner->offsetPos.y);

	//normalisation de la distance
	sf::Vector2f normDelta = VectorTools::NormaliseVector(sf::Vector2f(deltaPosX, deltaPosY));

	//pour toujours s'orienter vers le player
	float rot = std::atan2(deltaPosY, deltaPosX) * 180 / std::_Pi;
	Owner->rotation = rot + offsetAngle;

	////avant d'appliquer directement l'input, on va tester cette acceleration
	sf::Vector2f acceleration = inertia;
	acceleration.x += normDelta.x * speed * deltaTime * 0.0001f;
	acceleration.y += normDelta.y * speed * deltaTime * 0.0001f;

	////ton vérifie que l'acceleration ne sera pas trop grande avant de l'appliquer
	if (VectorTools::Length(acceleration) < maxVelocity)
	{
		inertia = acceleration;
	}


	////la force de ralentissement
	float dragForce = 1 - (drag * (deltaTime / 1000.f));

	////on applique cette force, proche de 0,999
	inertia *= dragForce;

	////on set la position, toujours en fonction du deltatime
	Owner->position = pos + (inertia * (deltaTime * 1.f));

	//Dans le cas où il y a une sortie de l'écran
	auto window = GameWindow::window;
	int leftBorder = 0;
	int topBorder = 0;
	int rightBorder = leftBorder + window->getSize().x;
	int bottomBorder = topBorder + window->getSize().y;

	////si on est trop à gauche on TP à droite
	if (Owner->position.x < leftBorder)
	{
		Owner->position.x = rightBorder;
	}if (Owner->position.y < topBorder)
	{
		Owner->position.y = bottomBorder;
	}if (Owner->position.x > rightBorder)
	{
		Owner->position.x = leftBorder;
	}if (Owner->position.y > bottomBorder)
	{
		Owner->position.y = topBorder;
	}

	//calcul la distance entre le player afin de déterminer si un shoot est autorisé
	distance = sqrt(pow((Playerposition.x - pos.x), 2) + (pow((Playerposition.y - pos.y), 2)));
}