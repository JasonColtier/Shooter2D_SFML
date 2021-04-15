#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>
#include "Singleton.h"

class CollisionComponent;

class CollisionManager : public Singleton<CollisionManager>
{

public:
	friend class Singleton<CollisionManager>;


	void UpdateCollision(std::vector<CollisionComponent*>& abscisseTab);

private:

	CollisionManager() = default;


	void SortByAbscisse(std::vector<CollisionComponent*>& abscisseTab) const;

	void CheckCollision(CollisionComponent* g1, CollisionComponent* g2) const;
};

#endif //COLLISIONMANAGER_H
