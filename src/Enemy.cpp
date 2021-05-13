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
#include "Spawner.h"
#include <vector>
#include <iostream>
#include <iterator>
#include "Managers/TextureManager.h"

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

	if (m_movementCompo->m_distance <= 300)
	{
		//modifier le changement de vitesse par le biai d'un multiplicateur
		//m_movementCompo->m_speed = 0.0000005f;
		//m_shootComponent->m_wantToShoot = true;
		m_shootComponent->m_fireRate = 10.0f;
		//Print::PrintLog("Shoot Enabled");		
	}
	else
	{
		//m_movementCompo->m_speed = 0.001f;
		m_shootComponent->m_wantToShoot = false;
		//Print::PrintLog("Shoot Not Enabled");
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
			}
		}
		
	}
	
}