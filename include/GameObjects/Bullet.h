﻿#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics/Texture.hpp>

#include "GameObjects/GameObject.h"
#include "Managers/TextureManager.h"

class Bullet : public GameObject
{
public:

	Bullet(sf::Vector2f position, sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f,sf::Texture* texture = TextureManager::GetTexturePtr(TextureManager::ETextures::Bullet),bool piercing = false);
	~Bullet() override = default;

	void Activate(sf::Vector2f position, sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f,sf::Texture* texture = TextureManager::GetTexturePtr(TextureManager::ETextures::Bullet),bool piercing = false);

	void Tick(int64_t deltaTime) override;

	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "Bullet"; }

	float GetDammage() const
	{
		return m_damage * m_damageMultiplier;
	}

	float GetSpeed() const
	{
		return m_speed * m_speedMultiplier;
	}

	//sf::Vector2f scale = sf::Vector2f(1, 1);
	float m_autoDestroyDelay = 0;
	float m_speedMultiplier = 1.f;
	float m_damageMultiplier = 1.f;

	bool m_piercing = false; //transperce les ennemis ?

protected:
	float m_speed = 0.5f;
	float m_timer = 0.f;
	float m_damage = 1.f;
};
#endif //BULLET_H