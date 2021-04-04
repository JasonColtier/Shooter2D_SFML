#include "GameLevel.h"
#include "Player.h"

GameLevel::GameLevel()
{
    Print::PrintString("level created");
    player = new Player();

    
    gameObjectsList.push_back(player);
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
    for (GameObject* gameObject : gameObjectsList)
    {
        gameObject->Render(window);
    }
}
