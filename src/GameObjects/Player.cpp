﻿#include "GameObjects/Player.h"

#include <random>
#include <SFML/Window/Mouse.hpp>
#include "GameLevel.h"
#include "GameWorld.h"
#include "Components/MovementComponent.h"
#include "Tools/Print.h"
#include "Components/ShootComponent.h"
#include "Tools/VectorTools.h"



Player::Player()
{
    Print::PrintLog("new player");

    RenderComponent* renderComponent = new RenderComponent(this,GameWorld::window,TextureManager::GetTexturePtr(TextureManager::Ship));
    renderComponent->sprite.setOrigin(sf::Vector2f(50.f, 50.f));
    renderComponent->sprite.setScale(sf::Vector2f(0.5f, 0.5f));

    // //offset pour que le nez du vaisseau soit vers la souris
    offsetPos = sf::Vector2f(25.f, 25.f);
    
    AddComponent(renderComponent);
    AddComponent(new ShootComponent());
    AddComponent(new MovementComponent());

    //position de départ du vaisseau
    // position = ;

}


void Player::Tick(int64_t deltaTime)
{
    GameObject::Tick(deltaTime);
    
   
}


