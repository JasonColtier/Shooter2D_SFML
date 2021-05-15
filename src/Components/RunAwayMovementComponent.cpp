#include "Components/RunAwayMovementComponent.h"
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


void RunAwayMovementComponent::TickComponent(int64_t deltaTime)
{
	BaseEnemyMovemementComponent::TickComponent(deltaTime);

	const auto Pos = m_owner->m_position;

	//Pour le comportement sp�cifique aux mouvements (peut �tre � modifier)
	if (300 < m_distance && m_distance < 350)
	{
		m_canMove = true;
	}
	else if (m_distance < 275)
	{
		m_canMove = true;
		m_escape = true;
	}
	else
	{
		m_canMove = true;
		m_escape = false;		
	}

	//Permet le mouvement de l'ennemi en fonction de son comportement
	if (m_canMove == true)
	{
		if (m_escape == false)
		{
			m_offsetAngle = 90.f;
			m_owner->m_position = Pos + (m_inertia * (static_cast<float>(deltaTime) * 1.f));
		}
		else
		{
			m_offsetAngle = -90.f;
			m_owner->m_position = Pos - (m_inertia * (static_cast<float>(deltaTime) * 1.f));
		}
		
	}

}
