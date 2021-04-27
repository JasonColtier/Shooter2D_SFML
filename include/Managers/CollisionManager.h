#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <list>

class CollisionHandler;
class GameObject;

class CollisionManager
{

public:

	static void UpdateCollision(std::list<GameObject*>& abscisseTab);

private:

	CollisionManager() = default;


	static void SortByAbscisse(std::list<GameObject*>& abscisseTab);

	static void CheckCollision(CollisionHandler* g1, CollisionHandler* g2);
};

#endif //COLLISIONMANAGER_H
