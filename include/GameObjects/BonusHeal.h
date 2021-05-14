#ifndef BONUSHEAL_H
#define BONUSHEAL_H

#include "IBonus.h"
#include "Components/RenderHandler.h"
#include "Managers/TextureManager.h"

class BonusHeal final: public IBonus
{
public:
	BonusHeal() = default;
	~BonusHeal() override = default;

	void Activate(sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f offsetPos = sf::Vector2f(0,0), float scale = 1.f, float rotation = 0) override
	{
		SetRenderHandler(TextureManager::GetTexturePtr(TextureManager::ETextures::Heart), "heart", 3);
	}

	void Deactivate() override
	{
		IBonus::Deactivate();
	}
	
	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "BonusHeal"; }

public:
	int m_pdtVie = 1;
};

#endif //BONUSHEAL_H
