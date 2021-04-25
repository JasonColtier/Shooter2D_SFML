#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Singleton.h"

class GameLevel;

namespace sf
{
    class Clock;
    class RenderWindow;
}

class GameLoop : public Singleton<GameLoop>
{

    friend class Singleton<GameLoop>;

public:
    

    void StartGame();

private:
    GameLoop();
    ~GameLoop();
    
    float targetFPS = 60.0f;

    //temps entre chaque frame
    int64_t deltaTime; //en microsecondes !
    int updateTime = 0;//temps pour faire toutes les boucles updates avant un rendu
    int updateSurplus = 0;//temps pour faire toutes les boucles updates avant un rendu

    GameLevel* gameLevel;

    //update all game objects
    void Update();
    //after all updates, one render
    void Render() const;
};
#endif
