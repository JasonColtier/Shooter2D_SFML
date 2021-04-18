#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>
#include "Singleton.h"

class CollisionComponent;

class CollisionManager
{

public:

	static void UpdateCollision(std::vector<CollisionComponent*>& abscisseTab);

private:

	CollisionManager() = default;


	static void SortByAbscisse(std::vector<CollisionComponent*>& abscisseTab);

	static void CheckCollision(CollisionComponent* g1, CollisionComponent* g2);
};

#endif //COLLISIONMANAGER_H
