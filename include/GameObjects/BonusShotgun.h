#ifndef BONUSSHOTGUN_H
#define BONUSSHOTGUN_H

#include "IBonus.h"
#include "Components/RenderHandler.h"
#include "Managers/TextureManager.h"

class BonusShotgun : public IBonus
{
public:
	BonusShotgun(sf::Vector2f position = sf::Vector2f(0.f, 0.f), sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f) : IBonus(position,offsetPos,scale,rotation)
	{
		m_renderHandler = new RenderHandler(this);
		m_renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::ETextures::Shotgun), "Shotgun", 3);
	};
	~BonusShotgun() override = default; 

	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "BonusShotgun"; }
};

#endif
