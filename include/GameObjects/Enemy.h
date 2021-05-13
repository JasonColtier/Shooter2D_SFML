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
	Enemy();
	~Enemy() override = default;

	void Tick(int64_t deltaTime) override;

	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "Enemy"; }

	void Deactivate() override;

private:
	void _SpawnBonus();

	int m_chanceToSpawnBonus = 100;  // en %


};
#endif //ENEMY_H