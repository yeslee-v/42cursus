//
// Created by Yeshin Lee on 2022/01/29.
//

#include "Span.hpp"

int main()
{
    {
        std::cout << "[ Test in subject ]" << std::endl;
        try {
            Span sp = Span(5);
            sp.addNumber(5);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << "[ Test MAX num: 1000 ]" << std::endl;
        try {
            Span sp = Span(MAX);
            for (int i = 0; i < MAX; i++)
                sp.addNumber(i * 10);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

}