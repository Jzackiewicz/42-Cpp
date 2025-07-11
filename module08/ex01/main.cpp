#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(void)
{
    // 50000000 will take about 30 seconds
    unsigned int numbersCount = 500000;
    Span sp = Span(numbersCount);
    std::vector<int> numbersVec;
    
    srand(time(0));
    for (unsigned int i = 0; i < numbersCount; ++i)
        numbersVec.push_back(rand());
    sp.addNumbers(numbersVec.begin(), numbersVec.end());

    std::cout << "Added " << numbersCount << " random numbers to the Span." << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    Span sp2 = Span(5);
    sp2.addNumber(6);
    sp2.addNumber(3);
    sp2.addNumber(17);
    sp2.addNumber(9);
    sp2.addNumber(11);
    // sp2.addNumber(6);
    std::cout << "Added 5 numbers to the Span2." << std::endl;
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    return (0);
}
