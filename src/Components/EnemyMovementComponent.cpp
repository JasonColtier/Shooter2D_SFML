#include "Components/EnemyMovementComponent.h"
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

void KamikazeMovementComponent::TickComponent(int64_t deltaTime)
{
	const auto* Level = GameWindow::GetGameLevel();
	m_playerposition = Level->m_player->m_position;
	const auto Pos = m_owner->m_position;

	//calcul de la disance avec le player
	const auto deltaPosX = m_playerposition.x - (Pos.x + m_owner->m_offsetPos.x);
	const auto deltaPosY = m_playerposition.y - (Pos.y + m_owner->m_offsetPos.y);

	//normalisation de la distance
	const sf::Vector2f normDelta = VectorTools::NormaliseVector(sf::Vector2f(deltaPosX, deltaPosY));

	//pour toujours s'orienter vers le player
	const float rot = (std::atan2(deltaPosY, deltaPosX)) * 180.0f / PI;
	m_owner->m_rotation = rot + m_offsetAngle;

	////avant d'appliquer directement l'input, on va tester cette acceleration
	sf::Vector2f acceleration = m_inertia;
	acceleration.x += normDelta.x * m_speed * static_cast<float>(deltaTime) * 0.0001f;
	acceleration.y += normDelta.y * m_speed * static_cast<float>(deltaTime) * 0.0001f;

	////ton vérifie que l'acceleration ne sera pas trop grande avant de l'appliquer
	if (VectorTools::Length(acceleration) < m_maxVelocity)
	{
		m_inertia = acceleration;
	}

	////la force de ralentissement
	const auto dragForce = 1.f - (m_drag * (static_cast<float>(deltaTime) / 1000.f));

	////on applique cette force, proche de 0,999
	m_inertia *= dragForce;

	////on set la position, toujours en fonction du deltatime
	m_owner->m_position = Pos + (m_inertia * (static_cast<float>(deltaTime) * 1.f));

	//Dans le cas où il y a une sortie de l'écran
	const auto* window = GameWindow::m_window;
	const auto leftBorder = 0.f;
	const auto topBorder = 0.f;
	const auto rightBorder = leftBorder + static_cast<float>(window->getSize().x);
	const auto bottomBorder = topBorder + static_cast<float>(window->getSize().y);

	////si on est trop à gauche on TP à droite
	if (m_owner->m_position.x < leftBorder)
	{
		m_owner->m_position.x = rightBorder;
	}
	else if (m_owner->m_position.x > rightBorder)
	{
		m_owner->m_position.x = leftBorder;
	}
	if (m_owner->m_position.y < topBorder)
	{
		m_owner->m_position.y = bottomBorder;
	}
	else if (m_owner->m_position.y > bottomBorder)
	{
		m_owner->m_position.y = topBorder;
	}

	//calcul la distance entre le player afin de déterminer si un shoot est autorisé
	m_distance = sqrt(pow((m_playerposition.x - Pos.x), 2) + (pow((m_playerposition.y - Pos.y), 2)));
}
