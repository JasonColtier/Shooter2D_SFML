#ifndef BONUSMOVEMENTSPEED_H
#define BONUSMOVEMENTSPEED_H

#include "IBonus.h"
#include "Components/RenderHandler.h"
#include "Managers/TextureManager.h"

class BonusMovementSpeed : public IBonus
{
public:
	BonusMovementSpeed() = default;
	~BonusMovementSpeed() override = default;

	void Activate(sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f offsetPos = sf::Vector2f(0,0), float scale = 1.f, float rotation = 0) override
	{
		SetRenderHandler(TextureManager::GetTexturePtr(TextureManager::ETextures::SpeedArrow), "BonusMovementSpeed", 3);
	}

	void Deactivate() override
	{
		IBonus::Deactivate();
	}

	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "BonusMovementSpeed"; }
};

#endif
