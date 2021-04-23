#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <list>

class CollisionComponent;
class GameObject;

class CollisionManager
{

public:

	static void UpdateCollision(std::list<GameObject*>& abscisseTab);

private:

	CollisionManager() = default;


	static void SortByAbscisse(std::list<GameObject*>& abscisseTab);

	static void CheckCollision(CollisionComponent* g1, CollisionComponent* g2);
};

#endif //COLLISIONMANAGER_H
