#include "Enemy.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameLevel.h"
#include "GameLoop.h"
#include "GameObjects/Player.h"
#include "Components/RenderComponent.h"
#include "GameWindow.h"
#include "Tools/VectorTools.h"
#include "Tools/Print.h"
#include <ostream>
#include <random>
#include <valarray>


Enemy::Enemy()
{	
	//Au moment du spawn
	Print::PrintLog("here comes a new challenger");
	renderComponent = new RenderComponent(this, TextureManager::GetTexturePtr(TextureManager::ShipEnemy), 1);
	renderComponent->sprite.setOrigin(sf::Vector2f(50.f, 50.f));
	renderComponent->sprite.setScale(sf::Vector2f(0.5f, 0.5f));	

}

void Enemy::Tick(int64_t deltaTime)
{
	GameObject::Tick(deltaTime);
}