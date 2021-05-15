#include "Components/KamikazeMovementComponent.h"
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
	BaseEnemyMovemementComponent::TickComponent(deltaTime);
	const auto Pos = m_owner->m_position;
	m_owner->m_position = Pos + (m_inertia * (static_cast<float>(deltaTime) * 1.f));
}