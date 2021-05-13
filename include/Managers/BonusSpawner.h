#ifndef BONUSSPAWNER_H
#define BONUSSPAWNER_H
#include "GameWindow.h"
#include "GameObjects/BonusHeal.h"
#include "GameObjects/BonusMultipleShot.h"

//typelist 
template <typename ...types>
struct TypeList
{
};

//toutes les classes bonus disponibles
using BonusTypes = TypeList<BonusHeal, BonusMultipleShot>;

//la template de base
template <typename ...Types>
struct SpawnBonus
{
    static void DoSpawn(int current, int wantedBonus, sf::Vector2f pos)
    {
    }
};

//template spécialisée, qui nous permet de parcourir nos classes de la typelist
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

//template spécialisée quand on arrive à la fin de la typelist
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

    static const int m_numberOfBonus = 2; //nombre de bonus dans notre typelist
    static const int m_chanceToSpawnBonus = 100; // en %

    static void RollBonus(sf::Vector2f pos)
    {
        int range = 100 - 1;
        auto roll = rand() % range;

        srand(time(0));//on seed pour s'assurer que notre random sera différent à chaque fois

        if (roll <= m_chanceToSpawnBonus)
        {
            auto wantedBonus = std::rand() % m_numberOfBonus;
            SpawnBonus<BonusTypes>::DoSpawn(0, wantedBonus, pos);
        }
    }
};

#endif
