#include "GameLevel.h"

#include <ostream>

#include "GameObjects/Player.h"
#include "Tools/Print.h"
#include <typeinfo>
#include "Managers/CollisionManager.h"

GameLevel::GameLevel()
{
	Print::PrintLog("level created");

    Print::PrintLog("level created");
    player = SpawnObject<Player>();
    player->position = sf::Vector2f(300.f, 300.f);
}

void GameLevel::Update(int64_t deltaTime)
{
	auto copy = l_gameObjects;
    for (GameObject* gameObject : copy)
    {
        gameObject->Tick(deltaTime);
    }
	collisionManager->UpdateCollision(l_collisionComponents);
}

void GameLevel::Render(sf::RenderWindow* window)
{
	for (Component* rendered : l_renderComponents)
	{
		//TODO : render par index
		//TODO : render par activé / désactivé avec un break qnd on rencontre le premier objet désactivé
		rendered->TickComponent();
	}
}

