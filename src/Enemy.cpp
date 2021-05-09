#include "Enemy.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameLevel.h"
#include "GameLoop.h"
//#include "Player.h"
//#include "RenderHandler.h"
#include "GameObjects/Player.h"
#include "Components/RenderHandler.h"
#include "GameWindow.h"
#include "Tools/VectorTools.h"
#include "Tools/Print.h"
#include <ostream>
#include <random>
#include <valarray>

#include "Components/CollisionHandler.h"
#include "Managers/ScoreManager.h"


Enemy::Enemy()
{
	//Au moment du spawn
	Print::PrintLog("here comes a new challenger");

	renderHandler = new RenderHandler(this,TextureManager::GetTexturePtr(TextureManager::ShipEnemy),"enemy",1);

	auto sprite = renderHandler->GetSprite("enemy");

	if (sprite)
	{
		sprite->setOrigin(sf::Vector2f(50.f, 50.f));
		sprite->setScale(sf::Vector2f(1.f, 1.f));
	}
	
	auto* tmp = new std::vector<sf::Vector2f>{ sf::Vector2f(0.0f, -25.0f), sf::Vector2f(50.0f, 25.0f), sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-50.0f, 25.0f) };
	collisionHandler = new CollisionHandler(this, CollisionType::EnemyChannel, new std::vector<CollisionType>({CollisionType::EnemyChannel}), &rotation, 50, &position, tmp);

}

void Enemy::Tick(int64_t deltaTime)
{
	GameObject::Tick(deltaTime);
}

void Enemy::Deactivate()
{
	GameObject::Deactivate();
	ScoreManager::ModifyScore(1);//une façon d'augmenter le score rapide mais on peut faire mieux

}
