#ifndef BONUSSNIPER_H
#define BONUSSNIPER_H

#include "IBonus.h"
#include "Components/RenderHandler.h"
#include "Managers/TextureManager.h"

class BonusSniper : public IBonus
{
public:
	
	~BonusSniper() override = default;
	BonusSniper() = default;
	
	void Activate(sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f offsetPos = sf::Vector2f(0,0), float scale = 1.f, float rotation = 0) override
	{
		SetRenderHandler(TextureManager::GetTexturePtr(TextureManager::ETextures::Sniper), "Sniper", 3);
	};

	void Deactivate() override
	{
		IBonus::Deactivate();
	}
	


	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "BonusSniper"; }


};

#endif