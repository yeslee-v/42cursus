//
// Created by Yeshin Lee on 2022/01/18.
//

#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat bureaucrat("alphabet");

    try
    {
        /* do some stuff with bureaucrats */
        // 1. invalid grade
        // 2. getGrade -> invalid grade
        bureaucrat.setGrade(101);
        if (bureaucrat.getGrade() < MIN)
            bureaucrat.GradeTooLowException();
        else if (bureaucrat.getGrade() > MAX)
            bureaucrat.GradeTooHighException();
    }
    catch (std::exception & e)
    {
        std::cout << "hell\n";
        /* handle exception */

            std::cout << "too low" << std::endl;
////            std::cout << bureaucrat.GradeTooLowException() << std::cout;
//        if (bureaucrat.getGrade(0) > MAX)
//            std::cout << "too high" << std::endl;
//            std::cout << bureaucrat.GradeTooHighException() << std::cout;
    }
    return 0;
}
