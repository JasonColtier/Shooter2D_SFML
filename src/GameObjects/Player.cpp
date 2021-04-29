#include "GameObjects/Player.h"
#include <random>
#include <SFML/Window/Mouse.hpp>
#include "GameLevel.h"
#include "Components/CollisionHandler.h"
#include "Components/MovementComponent.h"
#include "Components/ShootBulletComponent.h"
#include "Tools/Print.h"
#include "Tools/VectorTools.h"
#include "Components/RenderHandler.h"

Player::Player()
{
	Print::PrintLog("new player");

	renderHandler = new RenderHandler(this, TextureManager::GetTexturePtr(TextureManager::Ship), 1);
	renderHandler->sprite.setOrigin(sf::Vector2f(50.f, 50.f));
	//renderHandler->sprite.setScale(sf::Vector2f(0.5f, 0.5f));

	auto* tmp = new std::vector<sf::Vector2f>{ sf::Vector2f(0.0f, -25.0f), sf::Vector2f(50.0f, 25.0f), sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-50.0f, 25.0f) };
	collisionHandler = new CollisionHandler(this, CollisionType::PlayerChannel, new std::vector<CollisionType>(), &rotation, 50, &position, tmp);
	//AddComponent(RenderHandler);
	offsetPos = sf::Vector2f(25.f, 25.f);
	AddComponent(new ShootBulletComponent());
	AddComponent(new MovementComponent());

	//position de départ du vaisseau
	// position = ;

}


void Player::Tick(int64_t deltaTime)
{
	GameObject::Tick(deltaTime);


}


