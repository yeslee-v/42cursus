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

typedef struct s_grade {
    int sign;
    int execute;
} t_grade;

class Form {
private:
    std::string name;
    bool is_signed;
    t_grade grade;
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
