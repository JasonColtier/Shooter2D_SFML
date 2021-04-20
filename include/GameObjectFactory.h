#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#include <cassert>

class GameObject;

template<class parent>
class ObjectFactory
{
public:

	template<class child>
	static child* Create()
	{
		return new child();
	}
};


class GameObjectFactory
{

public:
	
	template<class T>
	static GameObject* Create()
	{
		return ObjectFactory<GameObject>::Create<T>();
	}

};


#endif //GAMEOBJECTFACTORY_H
