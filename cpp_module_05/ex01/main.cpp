//
// Created by Yeshin Lee on 2022/01/18.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    Bureaucrat gamma("alpha", 51);
    Form omega("omega", 50, 50);

    std::cout << std::endl;
    std::cout << "[ Overriding operator<< ]" << std::endl;
    std::cout << gamma;
    std::cout << omega << std::endl;

    std::cout << "[ Case 1: Too High Grade ]" << std::endl;
    try
    {
        Form psi("psi", 151, 1);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "[ Case 2: Too Low Grade ]" << std::endl;
    try
    {
        Form chi("chi", 0, 150);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "[ Case 3: Sign failed ]" << std::endl;
    try
    {
        gamma.signForm(omega);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "[ Case 4: Sign success ]" << std::endl;
    try
    {
        for (int i = 2; i; i--)
            gamma.DecrementGrade();
        gamma.signForm(omega);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
