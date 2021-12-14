#include "iostream"
#include "phonebook.h"

int main()
{
    std::string opt;

    while (1)
    {
        std::cout << "Input Option: ";
        std::cin >> opt;

        if (opt == "ADD")
        {
            std::cout << "here is ADD" << std::endl;
        }
        else if (opt == "SEARCH")
        {
            std::cout << "here is SEARCH" << std::endl;
        }
        else if (opt == "EXIT")
        {
            std::cout << "here is EXIT" << std::endl;
            exit(0);
        }
    }

    return 0;
}
