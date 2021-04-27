#include "GameObjects/Player.h"
#include <random>
#include <SFML/Window/Mouse.hpp>
#include "GameLevel.h"
#include "GameWindow.h"
#include "Components/ClassicPistol.h"
#include "Components/MovementComponent.h"
#include "Components/ShotGun.h"
#include "Components/Sniper.h"
#include "Tools/Print.h"
#include "Tools/VectorTools.h"



Player::Player()
{
    Print::PrintLog("new player");

    renderComponent = new RenderComponent(this,TextureManager::GetTexturePtr(TextureManager::Ship),1);
    renderComponent->sprite.setOrigin(sf::Vector2f(50.f, 50.f));
    renderComponent->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
    
    //AddComponent(renderComponent);
    offsetPos = sf::Vector2f(0, 25.f);
    shootComponent = new Sniper();
    AddComponent(shootComponent);//TODO : fonction remove component(Component *)

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




