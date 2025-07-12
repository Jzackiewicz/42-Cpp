#include "MutantStack.hpp"
#include <iostream>
#include <list>

template <typename T>
void printMutantStack(MutantStack<T> &mstack)
{
	for (typename MutantStack<T>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << "{" <<*it << "} ";
	std::cout << "| Size: " << mstack.size() << std::endl;
}

template <typename T>
void printList(std::list<T> &lst)
{
	for (typename std::list<T>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << "| Size: " << lst.size() << std::endl;
}

template <typename T>
void addArray2Stack(MutantStack<T> &mstack, T *array, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		mstack.push(array[i]);
}

int main(void)
{
	MutantStack<int>			mstackInt;
	MutantStack<float>			mstackFloat;
	MutantStack<std::string>	mstackString;
	std::list<int>				lst;
	int							intArray[] = {5, 17, 3};
	float						floatArray[] = {1.1f, 0.234234f, -3.349f};
	std::string					stringArray[] = {"Dupa", "Kościotrupa"};
	
	std::cout << "MutantStack<int>:" << std::endl;
	addArray2Stack(mstackInt, intArray, 3);
	printMutantStack(mstackInt);
	mstackInt.pop();
	printMutantStack(mstackInt);

	std::cout << std::endl << "MutantStack<float>:" << std::endl;
	addArray2Stack(mstackFloat, floatArray, 3);
	printMutantStack(mstackFloat);

	std::cout << std::endl << "MutantStack<std::string>:" << std::endl;
	addArray2Stack(mstackString, stringArray, 2);
	printMutantStack(mstackString);
	mstackString.pop();
	mstackString.pop();
	printMutantStack(mstackString);

	std::cout << std::endl << "List<int>:" << std::endl;
	
	lst.insert(lst.end(), intArray, intArray + 3);
	printList(lst);
	lst.pop_back();
	printList(lst);
	return (0);
}
