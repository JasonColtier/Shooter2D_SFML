#include "GameLevel.h"

#include "GameObjects/Player.h"
#include "Tools/Print.h"
#include "Managers/CollisionManager.h"
#include "GameObjects/Bullet.h"

GameLevel::GameLevel()
{
	Print::PrintLog("level created");

	//TODO Faire spawn après la création du gamelevel dans gameLoop
	player = SpawnActor<Player>();
	player->position = sf::Vector2f(300.f, 300.f);

	//player = GameWorld::GetGameLevel()->SpawnActor<Player>();
	////player = SpawnObject<Player>();
}

void GameLevel::Update(int64_t deltaTime)
{
	for (GameObject* gameObject : l_gameObjects)
	{
		gameObject->Tick(deltaTime);
	}

	CollisionManager::UpdateCollision(l_gameObjects);
}

void GameLevel::Render(sf::RenderWindow* window)
{
	auto renderPrioritySort = [](GameObject* const g1, GameObject* const g2) -> bool
	{
		if (!g1->renderComponent || !g2->renderComponent) return g1->renderComponent > g2->renderComponent;
		if (g1->isActivated != g2->isActivated) return g1->isActivated > g2->isActivated;
		return (g1->renderComponent->zIndex) < (g2->renderComponent->zIndex);
	};

	l_gameObjects.sort(renderPrioritySort);

	for (auto* object : l_gameObjects)
	{
		if (!object->isActivated)
		{
			break;
		}
		//TODO : render par index
		//TODO : render par activé / désactivé avec un break qnd on rencontre le premier objet désactivé
		object->renderComponent->RenderUpdate();
	}
}

