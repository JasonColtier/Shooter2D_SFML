#include <list>

#include "GameLoop.h"


//class A
//{
//public:
//	A(int i) : m_i(i)
//	{}
//
//	int m_i;
//};
//
//
//class B : public A
//{
//public:
//	B(int i, int j) : A(i), m_j(j)
//	{}
//
//	int m_j;
//};
//
//class C : public A
//{
//public:
//	C(int i, std::string t) : A(i), m_t(t)
//	{}
//
//	std::string m_t;
//};
//
//
//
//template<class T = A, typename  ...Args>
//T* spawn(Args... args)
//{
//	return static_assert(new T(args...));
//	//T* tmp = nullptr;
//	
//	auto* tmp = new T(args...);
//	return tmp;
//}

int main()
{    
    GameLoop::GetInstance()->StartGame(); 

	//auto* tmp1 = spawn<A>(4);
	//std::cout << tmp1->m_i << std::endl;

	//auto* tmp2 = spawn<B>(4);
	//std::cout << tmp2->m_i << " , " << tmp2->m_j << std::endl;

	//auto* tmp3 = spawn<C>(4, "tmp3");
	//std::cout << tmp3->m_i << " , " << tmp3->m_t << std::endl;


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
