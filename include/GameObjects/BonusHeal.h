#ifndef BONUSHEAL_H
#define BONUSHEAL_H

#include "IBonus.h"
#include "Components/RenderHandler.h"

class BonusHeal final: public IBonus
{
public:
	BonusHeal()
	{
		m_renderHandler = new RenderHandler(this);
		m_renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::ETextures::Heart), "heart", 3);
	};
	~BonusHeal() override = default;

	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "BonusHeal"; }

public:
	int m_pdtVie = 1;
};

#endif //BONUSHEAL_H
