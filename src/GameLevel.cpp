#include "GameLevel.h"
#include "GameObjects/Player.h"
#include "Tools/Print.h"
#include "Managers/CollisionManager.h"
#include "GameObjects/GenericBullet.h"

GameLevel::GameLevel()
{
	Print::PrintLog("level created");

	player = SpawnActor<Player>();
	player->position = sf::Vector2f(300.f, 300.f);

	bgTexture = SpawnActor<BackgroundTexture>();

}

void GameLevel::Update(int64_t deltaTime)
{
	//une copie temporaire pour pouvoir instancier et ajouter de nouveaux objets dans l_gameObjects à l'intérieur de la loop
	auto copy = l_gameObjects;
	// Print::PrintLog("number of objects in level : ",copy.size());
	for (GameObject* gameObject : copy)
	{
		gameObject->Tick(deltaTime);
	}

	CollisionManager::UpdateCollision(l_abscisseGameObjects);
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
		if (!object->isActivated || !object->renderComponent)
		{
			break;
		}
		object->renderComponent->RenderUpdate();
	}
}

void GameLevel::DestroyGameObject(GameObject* gameObject)
{
	l_gameObjects.remove(gameObject);
	delete gameObject;
	gameObject = nullptr;
}

