#include "GameLevel.h"

#include <ostream>

#include "GameObjects/Player.h"
#include "Tools/Print.h"
#include <typeinfo>


GameLevel::GameLevel()
{
    Print::PrintLog("level created");
    player = SpawnObject<Player>();
    player->position = sf::Vector2f(300.f, 300.f);
}

void GameLevel::Update(int64_t deltaTime)
{
    for (GameObject* gameObject : l_gameObjects)
    {
        std::cout << "adresse" << &gameObject << std::endl;
        gameObject->Tick(deltaTime);
    }
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
