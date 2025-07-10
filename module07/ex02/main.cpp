#include "Array.hpp"
#include <iostream>
#include <sstream>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
	srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
	std::cout << "Array size: " << numbers.size() << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " - Passed index out of bounds" << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " - Passed index out of bounds" << std::endl;
    }
    try
	{
		numbers[123] = 0;
		std::cout << "Numbers[123]: " << numbers[123] << std::endl;
	}
	catch(const std::exception& e)
	{
        std::cerr << e.what() << " - Passed index out of bounds" << std::endl;
	}
	for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    
	Array<std::string> strings(4);
	try
	{
		for (int i = 0; i < 5; i++)
		{
			std::ostringstream oss;
			oss << "Some text " << i;
			strings[i] =  oss.str();
			std::cout << "i: " << i << " text: " << strings[i] << std::endl;
		}
	}
	catch(const std::exception& e)
	{
        std::cerr << e.what() << " - Passed index out of bounds" << std::endl;
	}
	
	return (0);
}