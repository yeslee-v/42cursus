//
// Created by Yeshin Lee on 2022/01/21.
//

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern: default constructor called" << std::endl;
}

Intern::Intern(const Intern &intern) {
    *this = intern;
}

Intern& Intern::operator=(const Intern &intern) {
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern: destructor called" << std::endl;
}

int ValidFormName(std::string name) {
    std::string FormName[3] = {
            "shrubberyCreation",
            "robotomyRequest",
            "presidentialPardon"
    };

    for (int i = 0; i < 3; i++)
    {
        if (FormName[i] == name)
            return i;
    }
    return -1;
}

Form* Intern::makeForm(std::string name, std::string target) {
    Form* form;
    int value = ValidFormName(name);

    switch (value) {
        case SC:
            form = new ShrubberyCreationForm(target);
            break;
        case RR:
            form = new RobotomyRequestForm(target);
            break;
        case PP:
            form = new PresidentialPardonForm(target);
            break;
        default:
            throw Intern::NotValidFormException();
    }
    std::cout << "Intern create " << name << std::endl;
    return form;
}

const char* Intern::NotValidFormException::what() const throw() {
    return "Invalid Form";
}
