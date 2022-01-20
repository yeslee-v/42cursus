//
// Created by Yeshin Lee on 2022/01/18.
//

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void ShrubberyCreationFormTest() {
    std::cout << "[ Case 1: ShrubberyCreationForm ]" << std::endl;

    Bureaucrat alpha("alpha", 84);
    ShrubberyCreationForm SCForm("SCForm");

    std::cout << std::endl;
    try
    {
        alpha.executeForm(SCForm);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try
    {
        alpha.signForm(SCForm);
        alpha.executeForm(SCForm);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void RobotomyRequestFormTest() {
    std::cout << "[ Case 2: RobotomyRequestForm ]" << std::endl;

    RobotomyRequestForm RRForm("RRForm");
    Bureaucrat beta("beta", 42);

    std::cout << std::endl;
    try
    {
        beta.executeForm(RRForm);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try
    {
        beta.signForm(RRForm);
        beta.executeForm(RRForm);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void PresidentialPardonFormTest() {
    std::cout << "[ Case 3: PresidentialPardonForm ]" << std::endl;

    PresidentialPardonForm PPForm("PPForm");
    Bureaucrat delta("delta", 2);

    std::cout << std::endl;
    try
    {
        delta.executeForm(PPForm);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try
    {
        delta.signForm(PPForm);
        delta.executeForm(PPForm);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}


int main(void) {
    ShrubberyCreationFormTest();
    std::cout << std::endl;
    RobotomyRequestFormTest();
    std::cout << std::endl;
    PresidentialPardonFormTest();

    return 0;
}
