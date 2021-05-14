#ifndef BONUSMULTIPLESHOT_H
#define BONUSMULTIPLESHOT_H

#include "IBonus.h"
#include "Components/RenderHandler.h"
#include "Managers/TextureManager.h"

class BonusMultipleShot : public IBonus
{
public:
	BonusMultipleShot() = default;
	~BonusMultipleShot() override = default;

	void Activate(sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f offsetPos = sf::Vector2f(0,0), float scale = 1.f, float rotation = 0) override
	{
		IBonus::Activate(position, offsetPos, scale, rotation);
		
		SetRenderHandler(TextureManager::GetTexturePtr(TextureManager::ETextures::MultipleShot), "MultipleShot", 3);
	}

	void Deactivate() override
	{
		IBonus::Deactivate();
	}

	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "BonusMultipleShot"; }
};

#endif //BONUSHEAL_H
