#ifndef TONCOLLISION_H
#define TONCOLLISION_H

#include <iostream>
#include "Enemy.h"
#include "GameObjects/Bullet.h"
#include "GameObjects/Player.h"
#include "GameObjects/BonusHeal.h"

template<typename GameObject1, typename GameObject2>
struct OnCollision
{
	static void Reaction(GameObject1&, GameObject2&) {}
};

template<>
struct OnCollision<Player, Enemy>
{
	static void Reaction(Player& player, Enemy& enemy)
	{
		std::cout << "Collision Enemy, Player" << std::endl;
	}
};

template<>
struct OnCollision<Player, Bullet>
{
	static void Reaction(Player& player, Bullet& bullet)
	{

	}
};

template<>
struct OnCollision<Enemy, Bullet>
{
	static void Reaction(Enemy& enemy, Bullet& bullet)
	{
		std::cout << "Collision Ennemy, Bullet" << std::endl;
		enemy.m_lifeComponent->ModifyHealth(-bullet.GetDammage());
		bullet.Deactivate();
	}
};

template<>
struct OnCollision<Player, BonusHeal>
{
	static void Reaction(Player& player, BonusHeal& bonusHeal)
	{

	}
};
#endif //TONCOLLISION_H