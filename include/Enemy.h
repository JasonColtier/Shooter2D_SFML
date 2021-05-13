#ifndef ENEMY_H
#define ENEMY_H

#include "GameObjects/Character.h"

//class RenderComponent;

//namespace sf
//{
//	class Texture;
//}

class Enemy : public Character
{
public:
	Enemy(sf::Vector2f position, sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f);
	~Enemy() override = default;

	void Tick(int64_t deltaTime) override;

	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "Enemy"; }

};
#endif //ENEMY_H