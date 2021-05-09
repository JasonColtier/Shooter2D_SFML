#include "GameLevel.h"

#include "Enemy.h"
#include "GameObjects/Player.h"
#include "Tools/Print.h"
#include "Managers/CollisionManager.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Bullet.h"
#include "Spawner.h"
#include "Components/CollisionHandler.h"
#include "HUD/PlayerHUD.h"
#include "Managers/AudioManager.h"


GameLevel::GameLevel()
{
	Print::PrintLog("game level construction");
}

void GameLevel::SpawnGameObjects()
{
	player = SpawnActor<Player>();
	player->position = sf::Vector2f(300.f, 300.f);

	SpawnActor<BackgroundTexture>();
	SpawnActor<Spawner>();

	AudioManager::PlayMusic(AudioManager::EmicGameMusic);
}


void GameLevel::Update(int64_t deltaTime)
{
	//une copie temporaire pour pouvoir instancier et ajouter de nouveaux objets dans l_gameObjects à l'intérieur de la loop
	auto copy = l_gameObjects;
	// Print::PrintLog("number of objects in level : ",copy.size());
	for (GameObject* gameObject : copy)
	{
		if (!gameObject->isActivated)
		{
			break;
		}
		gameObject->Tick(deltaTime);
	}

	CollisionManager::UpdateCollision(l_abscisseGameObjects);
}

void GameLevel::Render(sf::RenderWindow* window)
{
	//TODO commenter un peu tout ça
	/*
	 *	quand on active / désactive, on peut mettre dans une autre liste
	 */
	
	auto renderPrioritySort = [](GameObject* const g1, GameObject* const g2) -> bool
	{
		if (g1->isActivated != g2->isActivated) return g1->isActivated > g2->isActivated;
		if (!g1->renderHandler || !g2->renderHandler) return g1->renderHandler > g2->renderHandler;
		return (g1->renderHandler->mapSprites.begin()->second->zIndex) < (g2->renderHandler->mapSprites.begin()->second->zIndex);
	};

	//améliorer ce sort ? trie par insertion ?
	
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

