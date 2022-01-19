//
// Created by Yeshin Lee on 2022/01/18.
//

#include "Bureaucrat.hpp"

int main(void) {

    std::cout << std::endl;
    try
    {
        Bureaucrat alpha("alpha", 1);
        alpha.DecrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try
    {
        Bureaucrat alpha("beta", 150);
        alpha.IncrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
