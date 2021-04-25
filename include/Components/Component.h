#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdint>

class GameObject;

class Component
{
public:

	virtual ~Component() = default;
	virtual void TickComponent(int64_t deltaTime = 0) = 0;

	GameObject* Owner = nullptr;

	//est ce que notre component tick
	bool activateTick = true;
};

#endif //COMPONENT_H



