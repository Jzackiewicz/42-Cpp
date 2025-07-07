#include "BaseABC.hpp"

int main(void)
{
	Base *randClass = generate();
	identify(randClass);
	identify(*randClass);
	delete (randClass);

	D *d = new D();
	identify(d);
	identify(*d);
	delete (d);
}
