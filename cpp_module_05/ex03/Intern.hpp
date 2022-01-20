//
// Created by Yeshin Lee on 2022/01/21.
//

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

enum ExistForm {
    SC,
    RR,
    PP,
    };

class Intern {
public:
    Intern();
    Intern(const Intern& intern);
    Intern& operator=(const Intern& intern);
    ~Intern();

    Form* makeForm(std::string name, std::string target);

    class NotValidFormException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

int ValidFormName(std::string name);

#endif
