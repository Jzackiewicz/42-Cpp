#include "BaseABC.hpp"
#include <ctime>
#include <cstdlib>
#include <exception>

Base::~Base(void) {}

A::A(void)
{
	std::cout << "\033[1m\033[34m A class created \033[0m" << std::endl;
}
A::~A(void) {}

B::B(void)
{
	std::cout << "\033[1m\033[33m B class created \033[0m" << std::endl;
}
B::~B(void) {}

C::C(void)
{
	std::cout << "\033[1m\033[32m C class created \033[0m" << std::endl;
}
C::~C(void) {}

Base	*generate(void)
{
	srand(std::time(0));
	switch (rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "\033[34mThis is class A\033[0m";
	else if (dynamic_cast<B*>(p))
		std::cout << "\033[33mThis is class B\033[0m";
	else if (dynamic_cast<C*>(p))
		std::cout << "\033[32mThis is class C\033[0m";
	else
		std::cout << "Unknown class" << std::endl;
	std::cout << " - downcasting using pointers" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "\033[34mThis is class A\033[0m";
	}
	catch (std::exception &e) {}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "\033[33mThis is class B\033[0m";
	}
	catch (std::exception &e) {}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "\033[32mThis is class C\033[0m";
	}
	catch (std::exception &e) {}

	std::cout << " - downcasting using references" << std::endl;
}
