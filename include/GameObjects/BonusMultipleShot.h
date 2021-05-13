#ifndef BONUSMULTIPLESHOT_H
#define BONUSMULTIPLESHOT_H

#include "IBonus.h"
#include "Components/RenderHandler.h"
#include "Managers/TextureManager.h"

class BonusMultipleShot : public IBonus
{
public:
	BonusMultipleShot(sf::Vector2f position = sf::Vector2f(0.f, 0.f), sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f) : IBonus(position,offsetPos,scale,rotation)
	{
		m_renderHandler = new RenderHandler(this);
		m_renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::ETextures::MultipleShot), "MultipleShot", 3);
	};
	~BonusMultipleShot() override = default; 

	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "BonusMultipleShot"; }
};

#endif //BONUSHEAL_H
