#include "GameLevel.h"
#include "GameObjects/Player.h"
#include "Components/RenderComponent.h"
#include <typeinfo>


GameLevel::GameLevel()
{
    Print::PrintLog("level created");
    player = new Player();

    SpawnObject(player,sf::Vector2f(300.f, 300.f));
}

void GameLevel::Update(int64_t deltaTime)
{
    for (GameObject* gameObject : l_gameObjects)
    {
        if(gameObject)
        {
            gameObject->Tick(deltaTime);
            gameObject->TickComponents(deltaTime);
        }
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

//TODO Changer cette fonction ! problème de pointeur vers des variables qui peuvent devenir nules ! 
void GameLevel::SpawnObject(GameObject* gameObject,sf::Vector2f& position)
{
    Print::PrintLog("spawn new object ! ",typeid(*gameObject).name());

    gameObject->position = position;
    
    l_gameObjects.push_back(gameObject);

    for (Component* component : gameObject->componentList)
    {
        if (typeid(*component) == typeid(RenderComponent))
        {
            l_renderComponents.push_back(component);
        }
    }
}
