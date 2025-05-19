#include <cstdio>
#include <iostream>

class Megaphone
{
	public:
	int test;
};

int main(void)
{
	Megaphone phone1;

	phone1.test = 1;

	std::cout << phone1.test << '\n';
}
