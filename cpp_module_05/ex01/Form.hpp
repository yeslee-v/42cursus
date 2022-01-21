//
// Created by Yeshin Lee on 2022/01/20.
//

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

enum check_signed {
    NOT_SIGNED,
    SIGNED
};

class Form {
private:
    const std::string name;
    bool is_signed;
    const int sign;
    const int execute;
public:
    Form(std::string name, int sign, int execute);
    Form(const Form& form);
    Form& operator=(const Form& form);
    ~Form();

    std::string getName() const;
    int getIsSigned() const;
    int getGradeRequired() const;
    int getGradeExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
