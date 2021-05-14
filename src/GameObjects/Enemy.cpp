#include "GameObjects/Enemy.h"
#include "GameLevel.h"
#include "GameObjects/Player.h"
#include "Components/RenderHandler.h"
#include "GameWindow.h"
#include "Tools/VectorTools.h"
#include "Tools/Print.h"
#include <random>
#include <valarray>
#include "Components/CollisionHandler.h"
#include <vector>
#include <iostream>
#include <iterator>
#include "Managers/TextureManager.h"

#include "StaticData.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/BonusHeal.h"
#include "GameObjects/Spawner.h"
#include "Managers/BonusSpawner.h"
#include "Managers/ScoreManager.h"


void Enemy::Tick(int64_t deltaTime)
{
    GameObject::Tick(deltaTime);

    if (m_movementCompo->m_distance <= 300)
    {
        //modifier le changement de vitesse par le biai d'un multiplicateur
        //m_movementCompo->m_speed = 0.0000005f;
        GetShootComponent()->m_wantToShoot = true;
        GetShootComponent()->m_baseFireRate = 10.0f;
        //Print::PrintLog("Shoot Enabled");		
    }
    else
    {
        //m_movementCompo->m_speed = 0.001f;
        GetShootComponent()->m_wantToShoot = false;
        //Print::PrintLog("Shoot Not Enabled");
    }
}

void Enemy::Activate(sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation)
{
    Character::Activate(position,offsetPos,scale,rotation);
    //Au moment du spawn
    Print::PrintLog("here comes a new challenger");

    SetRenderHandler(TextureManager::GetTexturePtr(TextureManager::ETextures::ShipEnemy), "enemy", 1);

    auto Sprite = GetRenderHandler()->GetRenderedItemWithKey<sf::Sprite>("enemy");

    if (Sprite)
    {
        Sprite->setOrigin(sf::Vector2f(50.f, 50.f));
        Sprite->setScale(sf::Vector2f(1.f, 1.f));
    }

    SetCollisionHandler(CollisionType::EnemyChannel, StaticData::ShipCollision,50, std::vector<CollisionType>({CollisionType::EnemyChannel, CollisionType::BonusChannel, CollisionType::EnemyProjectileChannel}));
}

void Enemy::Deactivate()
{
    Character::Deactivate();

    ScoreManager::ModifyScore(1); //une façon d'augmenter le score
    BonusSpawner::RollBonus(m_position);

    auto ListEnnemi = m_enemySpawner->m_EnemyList;

    for (Enemy* currentEnemy : ListEnnemi)
    {
        if (currentEnemy == this)
        {
            m_enemySpawner->m_EnemyList.remove(currentEnemy);
        }
    }
}
