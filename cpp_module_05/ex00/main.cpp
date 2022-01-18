//
// Created by Yeshin Lee on 2022/01/18.
//

#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat bureaucrat;

    bureaucrat.getName("emily");
    try
    {
        /* do some stuff with bureaucrats */

        std::cout << bureaucrat.getName() << std::endl;
        std::cout << bureaucrat.getGrade(101) << std::endl;

    }
    catch (std::exception & e)
    {
        /* handle exception */
        if (bureaucrat.getGrade(0) < MIN)
            std::cout << "too low" << std::endl;
//            std::cout << bureaucrat.GradeTooLowException() << std::cout;
        if (bureaucrat.getGrade(0) > MAX)
            std::cout << "too high" << std::endl;
//            std::cout << bureaucrat.GradeTooHighException() << std::cout;
    }
    return 0;
}
