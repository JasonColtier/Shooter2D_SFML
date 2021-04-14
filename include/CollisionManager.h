#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>

class CollisionComponent;

class CollisionManager
{

public:

	CollisionManager() = default;

	void UpdateCollision(std::vector<CollisionComponent*>& abscisseTab);

private:

	void SortByAbscisse(std::vector<CollisionComponent*>& abscisseTab) const;

	void CheckCollision(CollisionComponent* g1, CollisionComponent* g2);
};

#endif //COLLISIONMANAGER_H
