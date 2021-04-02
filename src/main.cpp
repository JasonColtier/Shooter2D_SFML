#include <SFML/Graphics.hpp>
#include <iostream>
#include <ostream>

#include "GameLoop.h"
#include "TestSignalSimple.h"

int main()
{
    GameLoop::GetInstance();
    
    // /*
    //  *  Test du signal
    //  */
    // TestSignalSimple* testSignal = new TestSignalSimple();
    // testSignal->Test();
    //
    // //on se connecte depuis un autre endroit au même signal, on rajoute donc une autre connexion que celle dans TestSignal
    // testSignal->GetSignal().Connect([](const auto& myInt)
    // {
    //     std::cout << "print called in main : " << std::any_cast<int>(myInt) <<std::endl;
    // });
    //
    // //on demande une autre update du signal
    // testSignal->GetSignal()(12);

    return 0;
}
