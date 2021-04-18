#include "Managers/CollisionManager.h"
#include <algorithm>
#include "Components/CollisionComponent.h"
#include "GameObjects/GameObject.h"

void CollisionManager::UpdateCollision(std::vector<CollisionComponent*>& abscisseTab)
{
	SortByAbscisse(abscisseTab);

	for (int i = 0; i < abscisseTab.size(); ++i)
	{
		if (!abscisseTab[i]->Owner->isActivated)
		{
			break;
		}
		
		for (int j = i + 1; j < abscisseTab.size(); ++j)
		{
			if (abscisseTab[i]->GetEndAbscisse() > abscisseTab[j]->GetStartAbscisse() && abscisseTab[j]->Owner->isActivated)
			{
				CheckCollision(abscisseTab[i], abscisseTab[j]);
			}
			else
			{
				break;
			}
		}
	}
}

void CollisionManager::SortByAbscisse(std::vector<CollisionComponent*>& abscisseTab)
{
	auto abscisseSort = [](CollisionComponent* const g1, CollisionComponent* const g2) -> bool
	{
		if (g1->Owner->isActivated != g2->Owner->isActivated) return g1->Owner->isActivated > g2->Owner->isActivated;
		else return (g1->GetStartAbscisse()) < (g2->GetStartAbscisse());
	};

	std::sort(abscisseTab.begin(), abscisseTab.end(), abscisseSort);
}

void CollisionManager::CheckCollision(CollisionComponent* g1, CollisionComponent* g2)
{

	for (CollisionChannel channel : g1->l_ExcludedCollisionChannel)
	{
		if (channel == g2->e_Channel)
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
						g1->OnCollision(hitPoint, g2->Owner);
						g2->OnCollision(hitPoint, g1->Owner);
					}
				}
			}
		}
	}
}
