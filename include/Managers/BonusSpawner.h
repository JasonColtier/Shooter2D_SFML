#ifndef BONUSSPAWNER_H
#define BONUSSPAWNER_H
#include "GameWindow.h"
#include "GameObjects/BonusHeal.h"
#include "GameObjects/BonusMultipleShot.h"


template <typename ...types>
struct TypeList
{
};

using BonusTypes = TypeList<BonusHeal, BonusMultipleShot>;

template <typename ...Types>
struct SpawnBonus
{
    static void DoSpawn(int current, int wantedBonus, sf::Vector2f pos)
    {
    }
};

template <typename CurrentBonus, typename ...OtherBonus>
struct SpawnBonus<TypeList<CurrentBonus, OtherBonus...>>
{
    static void DoSpawn(int current, int wantedBonus, sf::Vector2f pos)
    {
        if (current != wantedBonus)
        {
            current++;
            SpawnBonus<TypeList<OtherBonus...>>::DoSpawn(current, wantedBonus, pos);
        }
        else
        {
            GameWindow::GetGameLevel()->SpawnActor<CurrentBonus>(pos);
            Print::PrintLog("spawned bonus !!");
        }
    }
};

template <>
struct SpawnBonus<TypeList<>>
{
    static void DoSpawn(int current, int wantedBonus, sf::Vector2f pos)
    {
    }
};

class BonusSpawner
{
public:

    static const int m_numberOfBonus = 2;
    static const int m_chanceToSpawnBonus = 100; // en %

    static void RollBonus(sf::Vector2f pos)
    {
        int range = 100 - 1;
        auto roll = rand() % range;

        if (roll <= m_chanceToSpawnBonus)
        {
            auto wantedBonus = std::rand() % m_numberOfBonus;
            Print::PrintLog("wanted bonus is : ", wantedBonus);
            SpawnBonus<BonusTypes>::DoSpawn(0, wantedBonus, pos);
        }
    }
};

#endif
