#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdint>

class GameObject;

class Component
{
public:

	virtual ~Component() = default;
	virtual void TickComponent(int64_t deltaTime = 0) = 0;

public:
	GameObject* Owner = nullptr;

};

#endif //COMPONENT_H



