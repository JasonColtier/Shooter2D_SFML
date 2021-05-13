#include "GameLevel.h"
#include "GameObjects/Player.h"
#include "Tools/Print.h"
#include "Managers/CollisionManager.h"
#include "Components/RenderHandler.h"
#include "GameObjects/Spawner.h"
#include "Components/CollisionHandler.h"
#include "Managers/AudioManager.h"

GameLevel::GameLevel()
{
	Print::PrintLog("game level construction");
}

void GameLevel::SpawnGameObjects()
{
	m_player = SpawnActor<Player>();
	m_player->m_position = sf::Vector2f(300.f, 300.f);

	auto* background = SpawnActor<GameObject>();
	background->m_renderHandler = new RenderHandler(background);
	background->m_renderHandler->AddSprite(TextureManager::GetTexturePtr(TextureManager::ETextures::SpaceBackground), "bg", 0, false);

	SpawnActor<Spawner>();

	AudioManager::PlayMusic(AudioManager::ESounds::EpicGameMusic);
}

void GameLevel::Update(int64_t deltaTime)
{
	//une copie temporaire pour pouvoir instancier et ajouter de nouveaux objets dans l_gameObjects à l'intérieur de la loop
	auto Copy = m_lGameObjects;
	// Print::PrintLog("number of objects in level : ",copy.size());
	for (auto* gameObject : Copy)
	{
		if (!gameObject->m_isActivated)
		{
			break;
		}
		gameObject->Tick(deltaTime);
	}

	CollisionManager::UpdateCollision(m_lAbscisseGameObjects);
}

void GameLevel::Render(sf::RenderWindow* window)
{
	//TODO commenter un peu tout ça
	/*
	 *	quand on active / désactive, on peut mettre dans une autre liste
	 */

	auto renderPrioritySort = [](GameObject* const g1, GameObject* const g2) -> bool
	{
		if (g1->m_isActivated != g2->m_isActivated) return g1->m_isActivated > g2->m_isActivated;
		if (!g1->m_renderHandler || !g2->m_renderHandler) return g1->m_renderHandler > g2->m_renderHandler;
		return (g1->m_renderHandler->m_renderedItems.at(0)->m_zIndex) < (g2->m_renderHandler->m_renderedItems.at(0)->m_zIndex);
	};

	//améliorer ce sort ? trie par insertion ?
	m_lGameObjects.sort(renderPrioritySort);

	for (auto* object : m_lGameObjects)
	{
		if (!object->m_isActivated || !object->m_renderHandler)
		{
			break;
		}
		object->m_renderHandler->RenderUpdate();
	}
}

