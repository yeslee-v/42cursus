//
// Created by Yeshin Lee on 2022/01/18.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name) : name(name) {
    this->grade = 50;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return this->name;
}

void Bureaucrat::setGrade(unsigned int score) {
    this->grade -= score;
}

int Bureaucrat::getGrade(void) const {
    return this->grade;
}

void Bureaucrat::GradeTooHighException(void) {
    std::cout << "Grade is too high" << std::endl;
}

void Bureaucrat::GradeTooLowException(void) {
    std::cout << "Grade is too low" << std::endl;
}

std::ostream& Bureaucrat::operator<<(std::ostream& out, const Bureaucrat &bureaucrat) {
    if (bureaucrat.grade < 0)
        throw GradeTooLowException();
    else if (bureaucrat.grade > 150)
        throw GradeTooHighException();
    out << bureaucrat.grade;
    return out;
}
