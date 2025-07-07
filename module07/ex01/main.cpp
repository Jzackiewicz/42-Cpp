#include "iter.hpp"
#include <iostream>

void printElement(std::string &element)
{
	std::cout << "\033[36m{" << element << "} \033[0m";
}

void squareInt(int &element)
{
	element *= element;
}

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::string strarr[] = {"Hello", "World", "42", "CPP"};
	size_t lengthInt = 5;
	size_t lengthStr = 4;

	::iter(arr, lengthInt, squareInt);
	for (size_t i = 0; i < lengthInt; ++i)
		std::cout << "\033[32m" << arr[i] << " \033[0m";
	std::cout << std::endl;
	
	::iter(strarr, lengthStr, printElement);
	std::cout << std::endl;

	return 0;
}