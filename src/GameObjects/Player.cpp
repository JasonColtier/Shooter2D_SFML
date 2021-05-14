#include "GameObjects/Player.h"
#include "Components/CollisionHandler.h"
#include "GameWindow.h"
#include "StaticData.h"
#include "Components/ClassicPistol.h"
#include "Components/PlayerMovementComponent.h"
#include "Tools/Print.h"
#include "Components/RenderHandler.h"
#include "Components/Sniper.h"
#include "HUD/PlayerHUD.h"
#include "Managers/TextureManager.h"


void Player::Tick(int64_t deltaTime)
{
	GameObject::Tick(deltaTime);
}

void Player::Activate(sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation)
{
	Character::Activate(position, offsetPos, scale, rotation);
	
	Print::PrintLog("new player");

	SetRenderHandler(TextureManager::GetTexturePtr(TextureManager::ETextures::Ship), "player", 1,true,sf::Vector2f(50,50),m_scale);

	m_offsetPos = sf::Vector2f(0, 25.f);
	SetShootComponent(new Sniper(this));
	SetCollisionHandler(CollisionType::PlayerChannel, StaticData::ShipCollision, 50, std::vector<CollisionType>({ CollisionType::PlayerChannel, CollisionType::PlayerProjectileChannel }));

	AddComponent(new PlayerMovementComponent());

	InputManager::GetSignal().Connect<Player>(this, &Player::OnInputChanged);
	auto* hud = GameWindow::GetGameLevel()->SpawnActor<PlayerHUD>();
	hud->m_player = this;
}

void Player::Deactivate()
{
	Character::Deactivate();
}

void Player::OnInputChanged(const InputMapping input) const
{
	if (input.first == InputsEnum::Shoot)
	{
		GetShootComponent()->m_wantToShoot = input.second;
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




