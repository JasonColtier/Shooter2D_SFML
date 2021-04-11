#include "GameLevel.h"
#include "Player.h"
#include <typeinfo>


GameLevel::GameLevel()
{
    Print::PrintString("level created");
    player = new Player();

    SpawnObject(player);
}

void GameLevel::Update(int64_t deltaTime)
{
    for (GameObject* gameObject : gameObjectsList)
    {
        gameObject->Tick(deltaTime);
    }
}

void GameLevel::Render(sf::RenderWindow* window)
{
    for (RenderedGameObject* rendered : renderedList)
    {
        //TODO : render par index
        rendered->Render(window);
    }
}

void GameLevel::SpawnObject(GameObject* gameObject)
{
    Print::PrintString("spawn new object !");
    gameObjectsList.push_back(gameObject);

    if(typeid(*gameObject) == typeid(Player))
    {
        Print::PrintString("add to render list");

        RenderedGameObject* rendered = static_cast<RenderedGameObject*>(gameObject);

        renderedList.push_back(rendered);
    }
}