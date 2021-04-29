#include "GameLevel.h"

#include "Enemy.h"
#include "GameObjects/Player.h"
#include "Tools/Print.h"
#include "Managers/CollisionManager.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Bullet.h"
#include "Spawner.h"
#include "Components/CollisionHandler.h"

GameLevel::GameLevel()
{
	Print::PrintLog("level created");

	player = SpawnActor<Player>();
	player->position = sf::Vector2f(300.f, 300.f);

	bgTexture = SpawnActor<BackgroundTexture>();
	SpawnActor<Spawner>();

	//auto* tmp = SpawnActor<Enemy>();
	//auto* col = new std::vector<sf::Vector2f>{ sf::Vector2f(0.0f, -25.0f), sf::Vector2f(50.0f, 25.0f), sf::Vector2f(0.0f, 10.0f), sf::Vector2f(-50.0f, 25.0f) };
	//tmp->collisionHandler = new CollisionHandler(tmp, CollisionType::PlayerChannel, new std::vector<CollisionType>(), &tmp->rotation, 50, &tmp->position, col);
	//tmp->position = sf::Vector2f(100.f, 100.f);
	//tmp->Activate();
	
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
		if (!g1->renderHandler || !g2->renderHandler) return g1->renderHandler > g2->renderHandler;
		if (g1->isActivated != g2->isActivated) return g1->isActivated > g2->isActivated;
		return (g1->renderHandler->zIndex) < (g2->renderHandler->zIndex);
	};

	l_gameObjects.sort(renderPrioritySort);

	for (auto* object : l_gameObjects)
	{
		if (!object->isActivated || !object->renderHandler)
		{
			break;
		}
		object->renderHandler->RenderUpdate();
	}
}

