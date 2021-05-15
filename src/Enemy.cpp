#include "Enemy.h"
#include "GameLevel.h"
#include "GameObjects/Player.h"
#include "Components/RenderHandler.h"
#include "GameWindow.h"
#include "Tools/VectorTools.h"
#include "Tools/Print.h"
#include <random>
#include <valarray>
#include "Components/CollisionHandler.h"
#include "EnemySpawner.h"
#include <vector>
#include <iostream>
#include <iterator>
#include "Managers/TextureManager.h"
#include "Components/BaseEnemyMovementComponent.h"

using std::vector;

Enemy::Enemy(sf::Vector2f position, sf::Vector2f offsetPos , float scale , float rotation ) : Character(position, offsetPos, scale, rotation)
{
	//Au moment du spawn
	Print::PrintLog("here comes a new challenger");

	m_renderHandler = new RenderHandler(this);
	m_renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::ETextures::ShipEnemy), "enemy", 1);

	auto* Sprite = m_renderHandler->GetRenderedItemWithKey<sf::Sprite>("enemy");

	if (Sprite)
	{
		Sprite->setOrigin(sf::Vector2f(50.f, 50.f));
		Sprite->setScale(sf::Vector2f(1.f, 1.f));
	}

	const auto Tmp = std::vector<sf::Vector2f>{ sf::Vector2f(0.0f, -25.0f), sf::Vector2f(50.0f, 25.0f), sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-50.0f, 25.0f) };
	m_collisionHandler = new CollisionHandler(this, CollisionType::EnemyChannel, std::vector<CollisionType>({ CollisionType::EnemyChannel, CollisionType::BonusChannel, CollisionType::EnemyProjectileChannel }), &m_rotation, 50, &m_position, Tmp);
	
}

void Enemy::Tick(int64_t deltaTime)
{
	GameObject::Tick(deltaTime);

	if (static_cast<BaseEnemyMovemementComponent*>(m_movementCompo)->m_escape == false)
	{

		if (m_movementCompo->m_distance <= m_shootComponent->m_range)
		{			
			m_shootComponent->m_wantToShoot = true;				
		}
		else
		{
			m_shootComponent->m_wantToShoot = false;
		}
	}
	else
	{
		m_shootComponent->m_wantToShoot = false;
	}	
}

void Enemy::OnDeath()
{
	if(m_lifeComponent->m_currentHealth <= 0)
	{
		auto ListEnnemi = m_enemySpawner->m_EnemyList;

		for (Enemy* currentEnemy : ListEnnemi)
		{
			if (currentEnemy == this)
			{
				m_enemySpawner->m_EnemyList.remove(currentEnemy);
				m_enemySpawner->m_nbEnemyEliminated++;
			}
		}
		
	}
	
}