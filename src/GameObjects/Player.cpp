#include "GameObjects/Player.h"
#include <random>
#include <SFML/Window/Mouse.hpp>
#include "GameLevel.h"
#include "Components/CollisionHandler.h"
#include "GameWindow.h"
#include "Components/ClassicPistol.h"
#include "Components/MovementComponent.h"
#include "Components/ShotGun.h"
#include "Components/Sniper.h"
#include "Tools/Print.h"
#include "Tools/VectorTools.h"
#include "Components/RenderHandler.h"

Player::Player()
{
	Print::PrintLog("new player");

    renderHandler = new RenderHandler(this,TextureManager::GetTexturePtr(TextureManager::Ship),1);
    renderHandler->sprite.setOrigin(sf::Vector2f(50.f, 50.f));
    renderHandler->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
    
    //AddComponent(renderComponent);
    offsetPos = sf::Vector2f(0, 25.f);
    shootComponent = new Sniper();
    AddComponent(shootComponent);//TODO : fonction remove component(Component *)

	auto* tmp = new std::vector<sf::Vector2f>{ sf::Vector2f(0.0f, -25.0f), sf::Vector2f(50.0f, 25.0f), sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-50.0f, 25.0f) };
	collisionHandler = new CollisionHandler(this, CollisionType::PlayerChannel, new std::vector<CollisionType>(), &rotation, 10, &position, tmp);
    AddComponent(new MovementComponent());

    InputManager::GetSignal().Connect<Player>(this, &Player::OnInputChanged);

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
}




