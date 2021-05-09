#ifndef COLLISIONDISPATCHER_H
#define COLLISIONDISPATCHER_H

#include <functional>
#include <stdexcept>
#include "Enemy.h"
#include "GameObjects/Bullet.h"
#include "GameObjects/Player.h"

using TypeId = int;
using FnType = std::function<void(GameObject&, GameObject&)>;

template<typename ...types>
struct TypeList
{};

using AllCollisionTypes = TypeList<Player, Enemy, Bullet>;

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
		std::cout << "Collision Ennemy, Player" << std::endl;
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

	}
};

template<template<typename, typename> class Functor, typename T1, typename T2TypeList>
struct DispatchOnT2
{};

template<template<typename, typename> class Functor, typename T1>
struct DispatchOnT2<Functor, T1, TypeList<> >
{
	static FnType checkType(TypeId t2) { throw std::runtime_error("Type not in typelist of Collision"); }
};

template<template<typename, typename> class Functor, typename T1, typename FirstT2Type, typename ...OtherT2Types>
struct DispatchOnT2<Functor, T1, TypeList<FirstT2Type, OtherT2Types...> >
{
	static FnType checkType(TypeId t2)
	{
		if (t2 == FirstT2Type::getClassTypeId())
		{
			return [](GameObject& go1, GameObject& go2)
			{
				Functor<T1, FirstT2Type>::Reaction(static_cast<T1&>(go1), static_cast<FirstT2Type&>(go2));
			};
		}
		return DispatchOnT2<Functor, T1, TypeList<OtherT2Types...> >::checkType(t2);
	}
};

template<template<typename, typename> class Functor, typename AllAdmissibleTypes, typename T1TypeList>
struct DispatchOnT1
{};

template<template<typename, typename> class Functor, typename AllAdissibleTypes>
struct DispatchOnT1<Functor, AllAdissibleTypes, TypeList<> >
{
	static FnType checkType(TypeId t1, TypeId t2) { throw std::runtime_error("Type not in typelist of Collision"); }
};

template<template<typename, typename> class Functor, typename AllAdmissibleTypes, typename FirstT1Type, typename ...OtherT1Types>
struct DispatchOnT1<Functor, AllAdmissibleTypes, TypeList<FirstT1Type, OtherT1Types...> >
{

	static FnType checkType(TypeId t1, TypeId t2)
	{
		if (t1 == FirstT1Type::getClassTypeId())
		{
			return DispatchOnT2<Functor, FirstT1Type, AllAdmissibleTypes>::checkType(t2);
		}
		return DispatchOnT1<Functor, AllAdmissibleTypes, TypeList<OtherT1Types...> >::checkType(t1, t2);
	}
};

class CollisionDispatcher
{
public:

	static void DispatchOnCollision(GameObject& e1, GameObject& e2)
	{
		DispatchOnT1<OnCollision, AllCollisionTypes, AllCollisionTypes>::checkType(e1.getTypeId(), e2.getTypeId())(e1, e2);
	}
};

#endif //COLLISIONDISPATCHER_H