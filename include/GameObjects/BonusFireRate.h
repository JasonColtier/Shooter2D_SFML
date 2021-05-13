#ifndef BONUSFIRERATE_H
#define BONUSFIRERATE_H

#include "IBonus.h"
#include "Components/RenderHandler.h"
#include "Managers/TextureManager.h"

class BonusFireRate : public IBonus
{
public:
	BonusFireRate(sf::Vector2f position = sf::Vector2f(0.f, 0.f), sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f) : IBonus(position,offsetPos,scale,rotation)
	{
		m_renderHandler = new RenderHandler(this);
		m_renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::ETextures::FireRate), "BonusFireRate", 3);
	};
	~BonusFireRate() override = default; 

	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "BonusFireRate"; }
};

#endif //BONUSHEAL_H
