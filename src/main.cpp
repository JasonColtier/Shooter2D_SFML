#include <SFML/Graphics.hpp>
#include <iostream>
#include <ostream>
#include "TestSignalSimple.h"

int main()
{
    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    //
    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }
    //
    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }


    /*
     *  Test du signal
     */
    TestSignalSimple* testSignal = new TestSignalSimple();
    testSignal->Test();

    //on se connecte depuis un autre endroit au même signal, on rajoute donc une autre connexion que celle dans TestSignal
    testSignal->GetSignal().Connect([](const auto& myInt)
    {
        std::cout << "print called in main : " << std::any_cast<int>(myInt) <<std::endl;
    });

    //on demande une autre update du signal
    testSignal->GetSignal()(12);

    return 0;
}
