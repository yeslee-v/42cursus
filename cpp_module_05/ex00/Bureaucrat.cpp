//
// Created by Yeshin Lee on 2022/01/18.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(name), grade(grade) {}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    this->grade++;
    return this->grade;
}

void Bureaucrat::GradeTooHighException(int grade) {
    (void) grade;
    std::cout << "Grade is too high" << std::endl;
}

void Bureaucrat::GradeTooLowException(int grade) {
    (void) grade;
    std::cout << "Grade is too low" << std::endl;
}