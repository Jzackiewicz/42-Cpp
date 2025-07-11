#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iterator>

template <typename Container>
void useEasyfind(Container &container, int value)
{
    try
    {
        typename Container::iterator it = easyfind(container, value);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
	int arr[] = {-1, 0, 1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + 5);
	std::deque<int> deq(arr, arr + 5);

	useEasyfind(vec, 3);
	useEasyfind(deq, 6);
	useEasyfind(deq, -1);


	return 0;
}