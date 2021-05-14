#ifndef TONCOLLISION_H
#define TONCOLLISION_H

#include "Components/PlayerMovementComponent.h"
#include "Components/ShotGun.h"
#include "Components/Sniper.h"
#include "GameObjects/BonusFireRate.h"
#include "GameObjects/Enemy.h"
#include "GameObjects/Bullet.h"
#include "GameObjects/Player.h"
#include "GameObjects/BonusHeal.h"
#include "GameObjects/BonusMovementSpeed.h"
#include "GameObjects/BonusMultipleShot.h"
#include "GameObjects/BonusShotgun.h"
#include "GameObjects/BonusSniper.h"
#include "Tools/Print.h"

template <typename GameObject1, typename GameObject2>
struct OnCollision
{
    static void Reaction(GameObject1&, GameObject2&)
    {
    }
};

template <>
struct OnCollision<Player, Enemy>
{
    static void Reaction(Player& player, Enemy& enemy)
    {
        std::cout << "Collision Enemy, Player" << std::endl;
    }
};

template <>
struct OnCollision<Player, Bullet>
{
    static void Reaction(Player& player, Bullet& bullet)
    {
    }
};

template <>
struct OnCollision<Enemy, Bullet>
{
    static void Reaction(Enemy& enemy, Bullet& bullet)
    {
        std::cout << "Collision Ennemy, Bullet" << std::endl;
        enemy.m_lifeComponent->ModifyHealth(-bullet.GetDammage());
        bullet.Deactivate();
    }
};

template <>
struct OnCollision<Player, BonusHeal>
{
    static void Reaction(Player& player, BonusHeal& bonusHeal)
    {
        auto life = player.GetComponentOfClass<LifeComponent>();

        life->ModifyHealth(bonusHeal.m_pdtVie);
        Print::PrintLog("take heal ! ");
        bonusHeal.Deactivate();
    }
};

template <>
struct OnCollision<Player, BonusMultipleShot>
{
    static void Reaction(Player& player, BonusMultipleShot& bonusMultipleShot)
    {
        auto shoot = player.GetComponentOfClass<ShootComponent>();

        shoot->m_baseShootNumber ++;
        Print::PrintLog("multiple shoot ! ");
        bonusMultipleShot.Deactivate();
    }
};

template <>
struct OnCollision<Player, BonusFireRate>
{
    static void Reaction(Player& player, BonusFireRate& bonusFireRate)
    {
        auto shoot = player.GetComponentOfClass<ShootComponent>();

        shoot->m_fireRateModifier *= 0.5f;
        Print::PrintLog("fire rate up ! ");
        bonusFireRate.Deactivate();
    }
};

template <>
struct OnCollision<Player, BonusShotgun>
{
    static void Reaction(Player& player, BonusShotgun& bonusShotgun)
    {
        player.SetShootComponent(new ShotGun(*player.GetShootComponent()));
        
        Print::PrintLog("shotgun ! ");
        bonusShotgun.Deactivate();
    }
};

template <>
struct OnCollision<Player, BonusSniper>
{
    static void Reaction(Player& player, BonusSniper& bonusSniper)
    {
        player.SetShootComponent(new Sniper(*player.GetShootComponent()));
        
        Print::PrintLog("sniper ! ");
        bonusSniper.Deactivate();
    }
};

template <>
struct OnCollision<Player, BonusMovementSpeed>
{
    static void Reaction(Player& player, BonusMovementSpeed& movementSpeed)
    {
        player.GetComponentOfClass<PlayerMovementComponent>()->m_maxVelocity *= 1.5;
        
        Print::PrintLog("movement speed up ! ");
        movementSpeed.Deactivate();
    }
};

#endif //TONCOLLISION_H
