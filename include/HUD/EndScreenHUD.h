﻿#ifndef ENDSCREENHUD_H
#define ENDSCREENHUD_H

#include <SFML/Graphics/Text.hpp>
#include "GameObjects/GameObject.h"
#include "Managers/ScoreManager.h"

namespace sf {
	class Sprite;
}


class EndScreenHUD : public GameObject
{
public:

	EndScreenHUD() =default;
	~EndScreenHUD() = default;

	void Activate(sf::Vector2f position = sf::Vector2f(0.f, 0.f), sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f) override;

	void Deactivate() override
	{
		GameObject::Deactivate();

	}

};

#endif //PlayerHUD_H