#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <list>

class CollisionHandler;
class GameObject;

class CollisionManager
{
public:
	/// <summary>
	///	Appel�e � chaque frame pour actualiser les collisions entre les objets
	/// </summary>
	/// <param name="abscisseTab"> Liste des objets </param>
	static void UpdateCollision(std::list<GameObject*>& abscisseTab);

private:

	CollisionManager() = default;

	/// <summary>
	///Trie la liste des objets en fonction de la position des objets, de si ils sont activ�e et si ils poss�dent un CollisionHandler
	/// </summary>
	/// <param name="abscisseTab"> Liste des objets </param>
	static void _SortByAbscisse(std::list<GameObject*>& abscisseTab);

	/// <summary>
	/// Check les intersections entres les segments g�n�rer � partir de la liste de points du CollisionHandler des objets
	/// </summary>
	/// <param name="g1">Premi�re objet</param>
	/// <param name="g2">Deuxi�me objet</param>
	static void _CheckCollision(CollisionHandler* g1, CollisionHandler* g2);
};
#endif //COLLISIONMANAGER_H
