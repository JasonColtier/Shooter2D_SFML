#include "GameObjects/Player.h"
#include <random>
#include <SFML/Window/Mouse.hpp>
#include "GameLevel.h"
#include "Components/CollisionHandler.h"
#include "GameWindow.h"
#include "StaticData.h"
#include "Components/ClassicPistol.h"
#include "Components/LifeComponent.h"
#include "Components/MovementComponent.h"
#include "Components/ShotGun.h"
#include "Components/Sniper.h"
#include "Tools/Print.h"
#include "Tools/VectorTools.h"
#include "Components/RenderHandler.h"
#include "HUD/PlayerHUD.h"

Player::Player()
{
	Print::PrintLog("new player");

	renderHandler = new RenderHandler(this, TextureManager::GetTexturePtr(TextureManager::Ship), 1);
	renderHandler->sprite.setOrigin(sf::Vector2f(50.f, 50.f));
	renderHandler->sprite.setScale(sf::Vector2f(1.f, 1.f));

	offsetPos = sf::Vector2f(0, 25.f);
	shootComponent = new ClassicPistol();
	AddComponent(shootComponent);

	collisionHandler = new CollisionHandler(this, CollisionType::PlayerChannel, new std::vector<CollisionType>(), &rotation, 50, &position,StaticData::ShipCollision);
	AddComponent(new MovementComponent());

	InputManager::GetSignal().Connect<Player>(this, &Player::OnInputChanged);

	auto hud = GameWindow::GetGameLevel()->SpawnActor<PlayerHUD>();
	hud->player = this;
}


void Player::Tick(int64_t deltaTime)
{
	GameObject::Tick(deltaTime);

}

void Player::OnInputChanged(InputMapping input)
{
	if (input.first == Shoot)
	{
		shootComponent->wantToShoot = input.second;
	}

	if(input.first == DebugNum1)
	{
		lifeComponent->ModifyHealth(-1);
	}
	if(input.first == DebugNum2)
	{
		lifeComponent->ModifyHealth(+1);
	}
}




