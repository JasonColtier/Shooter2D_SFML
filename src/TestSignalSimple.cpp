#include "TestSignalSimple.h"

#include <iostream>
#include <iterator>
#include <ostream>


TestSignalSimple::TestSignalSimple()
{

}


void TestSignalSimple::Test()
{
    //que'est ce qu'on fait si on recoit un changement dans notre signal ?
    m_signal.Connect([this](const auto& myInt)
    {
        std::cout << "print called in Test : " << std::any_cast<int>(myInt) <<std::endl;
    });

    //on connecte une fonction membre
    m_signal.Connect<TestSignalSimple>(this,&TestSignalSimple::Print);
    
    //on call une update, toutes les fonctions connectées seront appelées
    m_signal(100);
}



void TestSignalSimple::Print(std::any i)
{
    std::cout << "print called here" <<std::endl;
}
