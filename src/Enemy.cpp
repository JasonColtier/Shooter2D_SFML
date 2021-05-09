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

#include "StaticData.h"
#include "Components/CollisionHandler.h"

Enemy::Enemy()
{
	////TODO mettre la récup du Player
	////player = .....

	//Print::PrintString("here comes a new challenger");

	//auto* RenderHandlers = new RenderHandler(this, GameLoop::GetInstance()->window, TextureManager::GetInstance()->GetTexturePtr(TextureManager::Ship));
	//RenderHandlers->sprite.setOrigin(sf::Vector2f(50.f, 50.f));
	//RenderHandlers->sprite.setScale(sf::Vector2f(1.0f, 1.0f));

	//AddComponent(RenderHandlers);

	////position de départ du vaisseau
	//position = sf::Vector2f(300.f, 300.f);


	////offset pour que le nez du vaisseau soit vers la souris
	//offsetPos.x = 100 * 0.5f / 2;
	//offsetPos.y = 100 * 0.5f / 2;
	//Au moment du spawn
	Print::PrintLog("here comes a new challenger");
	renderHandler = new RenderHandler(this, TextureManager::GetTexturePtr(TextureManager::ShipEnemy), 1);
	renderHandler->sprite.setOrigin(sf::Vector2f(50.f, 50.f));
	renderHandler->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	auto* tmp = new std::vector<sf::Vector2f>{ sf::Vector2f(0.0f, -25.0f), sf::Vector2f(50.0f, 25.0f), sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-50.0f, 25.0f) };
	collisionHandler = new CollisionHandler(this, CollisionType::EnemyChannel, new std::vector<CollisionType>{PlayerChannel, EnemyProjectileChannel}, & rotation, 50, & position, tmp);
}

void Enemy::Tick(int64_t deltaTime)
{
	GameObject::Tick(deltaTime);
}