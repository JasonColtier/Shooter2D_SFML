#ifndef COMPONENT_H
#define COMPONENT_H

class GameObject;

class Component
{
public:

    virtual ~Component() = default;

    virtual void TickComponent(int64_t deltaTime = 0) {};

    GameObject* Owner = nullptr;

    //est ce que notre component tick
    bool activateTick = false;
};

#endif //COMPONENT_H
