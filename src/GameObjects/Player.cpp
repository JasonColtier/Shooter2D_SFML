#include "GameObjects/Player.h"
#include "Components/CollisionHandler.h"
#include "GameWindow.h"
#include "StaticData.h"
#include "Components/ClassicPistol.h"
#include "Components/PlayerMovementComponent.h"
#include "Tools/Print.h"
#include "Components/RenderHandler.h"
#include "HUD/PlayerHUD.h"
#include "Managers/TextureManager.h"

//#include <random>
//#include <SFML/Window/Mouse.hpp>
//#include "GameLevel.h"
//#include "Components/LifeComponent.h"
//#include "Tools/VectorTools.h"


Player::Player(sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation) : Character(position, offsetPos, scale, rotation)
{
	Print::PrintLog("new player");

	m_renderHandler = new RenderHandler(this );
	m_renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::ETextures::Ship), "player", 1);
	auto* Sprite = m_renderHandler->GetRenderedItemWithKey<sf::Sprite>("player");
	m_scale = 0.5f;

	if (Sprite)
	{
		Sprite->setOrigin(sf::Vector2f(50.f, 50.f));
		Sprite->setScale(sf::Vector2f(m_scale, m_scale));
	}

	m_offsetPos = sf::Vector2f(0, 25.f);
	m_shootComponent = new ClassicPistol();
	AddComponent(m_shootComponent);

	m_collisionHandler = new CollisionHandler(this, CollisionType::PlayerChannel, std::vector<CollisionType>({ CollisionType::PlayerChannel, CollisionType::PlayerProjectileChannel }), &m_rotation, 50, &m_position, StaticData::ShipCollision);
	AddComponent(new PlayerMovementComponent());

	InputManager::GetSignal().Connect<Player>(this, &Player::OnInputChanged);
	auto* hud = GameWindow::GetGameLevel()->SpawnActor<PlayerHUD>(m_position);
	hud->m_player = this;
}

void Player::Tick(int64_t deltaTime)
{
	GameObject::Tick(deltaTime);
}

void Player::OnInputChanged(const InputMapping input) const
{
	if (input.first == InputsEnum::Shoot)
	{
		m_shootComponent->m_wantToShoot = input.second;
	}
	if (input.first == InputsEnum::DebugNum1)
	{
		m_lifeComponent->ModifyHealth(-1);
	}
	if (input.first == InputsEnum::DebugNum2)
	{
		m_lifeComponent->ModifyHealth(+1);
	}
}




