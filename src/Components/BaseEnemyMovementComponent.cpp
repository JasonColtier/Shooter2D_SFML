#include "Components/BaseEnemyMovementComponent.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameLevel.h"
#include "GameWindow.h"
#include "Components/IMovementComponent.h"
#include "Components/Component.h"
#include "GameObjects/Player.h"
#include "Tools/VectorTools.h"
#include <random>
#include <valarray>
#include <cmath>
#include "Tools/SMath.h"


void BaseEnemyMovemementComponent::TickComponent(int64_t deltaTime)
{
	m_playerposition = GameWindow::GetGameLevel()->m_player->m_position;
	const auto Pos = Owner->m_position;

	//calcul de la disance avec le player
	const auto DeltaPosX = m_playerposition.x - (Pos.x + Owner->m_offsetPos.x);
	const auto DeltaPosY = m_playerposition.y - (Pos.y + Owner->m_offsetPos.y);

	//normalisation de la distance
	const sf::Vector2f normDelta = VectorTools::NormaliseVector(sf::Vector2f(DeltaPosX, DeltaPosY));

	//pour toujours s'orienter vers le player
	const auto Rot = std::atan2(DeltaPosY, DeltaPosX) * 180 / PI;
	Owner->m_rotation = (Rot + static_cast<float>(m_offsetAngle));

	////avant d'appliquer directement l'input, on va tester cette acceleration
	sf::Vector2f Acceleration = m_inertia;
	Acceleration.x += normDelta.x * m_speed * static_cast<float>(deltaTime) * 0.0001f;
	Acceleration.y += normDelta.y * m_speed * static_cast<float>(deltaTime) * 0.0001f;

	////ton vérifie que l'acceleration ne sera pas trop grande avant de l'appliquer
	if (VectorTools::Length(Acceleration) < m_maxVelocity)
	{
		m_inertia = Acceleration;
	}

	////la force de ralentissement
	const auto DragForce = 1 - (m_drag * (static_cast<float>(deltaTime) / 1000.f));

	////on applique cette force, proche de 0,999
	m_inertia *= DragForce;


	//Dans le cas où il y a une sortie de l'écran
	auto* Window = GameWindow::m_window;
	const auto LeftBorder = 0.f;
	const auto TopBorder = 0.f;
	const auto RightBorder = LeftBorder + Window->getSize().x;
	const auto BottomBorder = TopBorder + Window->getSize().y;

	//va à la bordure de l'écran opposé quand il sort de l'écran
	if (Owner->m_position.x < LeftBorder)
	{
		Owner->m_position.x = RightBorder;
	}
	else if (Owner->m_position.x > RightBorder)
	{
		Owner->m_position.x = LeftBorder;
	}
	if (Owner->m_position.y < TopBorder)
	{
		Owner->m_position.y = BottomBorder;
	}
	else if (Owner->m_position.y > BottomBorder)
	{
		Owner->m_position.y = TopBorder;
	}

	//calcul la distance
	m_distance = sqrt(pow((m_playerposition.x - Pos.x), 2) + (pow((m_playerposition.y - Pos.y), 2)));
}