#include "Managers/CollisionManager.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/GameObject.h"
#include "Managers/CollisionDispatcher.h"

void CollisionManager::UpdateCollision(std::list<GameObject*>& abscisseTab)
{
	SortByAbscisse(abscisseTab);

	for (auto objet1 = abscisseTab.begin(); objet1 != abscisseTab.end(); ++objet1)
	{
		if (!(*objet1)->isActivated || !(*objet1)->collisionHandler)
		{
			break;
		}

		for (auto objet2 = std::next(objet1); objet2 != abscisseTab.end(); ++objet2)
		{
			if ((*objet2)->isActivated && (*objet2)->collisionHandler)
			{
				if ((*objet1)->collisionHandler->GetEndAbscisse() > (*objet2)->collisionHandler->GetStartAbscisse())
				{
					CheckCollision((*objet1)->collisionHandler, (*objet2)->collisionHandler);
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
			//for (int i = 0; i < abscisseTab.size(); ++i)
			//{
			//	if (!abscisseTab[i]->isActivated)
			//	{
			//		break;
			//	}
			//	for (int j = i + 1; j < abscisseTab.size(); ++j)
			//	{
			//if (abscisseTab[i]->collisionHandler->GetEndAbscisse() > abscisseTab[j]->collisionHandler->GetStartAbscisse() && abscisseTab[j]->isActivated)
			//{
			//	CheckCollision(abscisseTab[i]->collisionHandler, abscisseTab[j]->collisionHandler);
			//}
			//else
			//{
			//	break;
			//}
			//}
		//}
		}
	}
}

void CollisionManager::SortByAbscisse(std::list<GameObject*>& abscisseTab)
{
	auto abscisseSort = [](GameObject* const g1, GameObject* const g2) -> bool
	{
		if (!g1->collisionHandler || !g2->collisionHandler) return g1->collisionHandler > g2->collisionHandler;
		if (g1->isActivated != g2->isActivated) return g1->isActivated > g2->isActivated;
		return (g1->collisionHandler->GetStartAbscisse()) < (g2->collisionHandler->GetStartAbscisse());
	};
	abscisseTab.sort(abscisseSort);
}

void CollisionManager::CheckCollision(CollisionHandler* g1, CollisionHandler* g2)
{

	for (CollisionType channel : *g1->l_ExcludedCollisionType)
	{
		if (channel == g2->e_Type)
		{
			return;
		}
	}

	const auto dist = sqrtf(pow(g2->position->x - g1->position->x, 2) + pow(g2->position->y - g1->position->y, 2));
	const auto maxDist = g1->radius + g2->radius;

	if (dist < maxDist)
	{
		auto l_g1 = g1->getPoints();
		auto l_g2 = g2->getPoints();

		for (int i = 0; i < l_g1.size(); ++i)
		{
			sf::Vector2f* point_A = &l_g1[i];
			sf::Vector2f* point_B;

			if (i + 1 >= l_g1.size())
			{
				point_B = &l_g1[0];
			}
			else
			{
				point_B = &l_g1[i + 1];
			}

			for (int j = 0; j < l_g2.size(); ++j)
			{
				sf::Vector2f* point_C = &l_g2[j];
				sf::Vector2f* point_D;
				if ((j + 1) >= l_g2.size())
				{
					point_D = &l_g2[0];
				}
				else
				{
					point_D = &l_g2[(j + 1)];
				}

				const auto det = (point_B->x - point_A->x) * (point_C->y - point_D->y) - (point_C->x - point_D->x) * (point_B->y - point_A->y);

				if (det != 0.0f)
				{
					const auto t1 = ((point_C->x - point_A->x) * (point_C->y - point_D->y) - (point_C->x - point_D->x) * (point_C->y - point_A->y)) / det;
					const auto t2 = ((point_B->x - point_A->x) * (point_C->y - point_A->y) - (point_C->x - point_A->x) * (point_B->y - point_A->y)) / det;

					if (t1 <= 1 && t1 >= 0 && t2 <= 1 && t2 >= 0)
					{
						const sf::Vector2f hitPoint = sf::Vector2f((point_A->x + t1 * (point_B->x - point_A->x)), point_A->y + t1 * (point_B->y - point_A->y));
						CollisionDispatcher::DispatchOnCollision(*g1->owner, *g2->owner);
						//g1->owner->OnCollision(hitPoint, g2->owner);
						//g2->owner->OnCollision(hitPoint, g1->owner);
					}
				}
			}
		}
	}
}
