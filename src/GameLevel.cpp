#include "GameLevel.h"
#include "Player.h"
//#include "Enemy.h"
#include "RenderComponent.h"
#include <typeinfo>
#include "CollisionManager.h"
#include "CollisionComponent.h"

GameLevel::GameLevel()
{
	Print::PrintString("level created");
	player = new Player();
	//enemy = new Enemy();
	collisionManager = CollisionManager::GetInstance();

	SpawnObject(player);
	//SpawnObject(enemy);
}

void GameLevel::Update(int64_t deltaTime)
{
	collisionManager->UpdateCollision(l_collisionComponents);
	
	for (GameObject* gameObject : l_gameObjects)
	{
		gameObject->Tick(deltaTime);
	}
	
}

void GameLevel::Render(sf::RenderWindow* window)
{
	for (Component* rendered : l_renderComponents)
	{
		//TODO : render par index
		//TODO : render par activé / désactivé avec un break qnd on rencontre le premier objet désactivé
		rendered->UpdateComponent();
	}
}

void GameLevel::SpawnObject(GameObject* gameObject)
{
	Print::PrintString("spawn new object !");
	l_gameObjects.push_back(gameObject);


	for (Component* component : gameObject->componentList)
	{
		if (typeid(*component) == typeid(RenderComponent))
		{
			l_renderComponents.push_back(component);
		}
		if (typeid(*component) == typeid(CollisionComponent))
		{
			l_collisionComponents.push_back(dynamic_cast<CollisionComponent*>(component));
		}
	}
}
