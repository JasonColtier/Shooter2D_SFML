#ifndef COMPONENT_H
#define COMPONENT_H

class GameObject;

class Component
{
public:

	virtual ~Component() = default;

	virtual void UpdateComponent() = 0;


	GameObject* Owner = nullptr;
};

#endif //COMPONENT_H
