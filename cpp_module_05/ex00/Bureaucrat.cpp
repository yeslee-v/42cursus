//
// Created by Yeshin Lee on 2022/01/18.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(name), grade(grade) {}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade(unsigned int score) const {
    this->grade -= score;
    return this->grade;
}

void Bureaucrat::GradeTooHighException(void) {
    std::cout << "Grade is too high" << std::endl;
}

void Bureaucrat::GradeTooLowException(void) {
    std::cout << "Grade is too low" << std::endl;
}

std::ostream& Bureaucrat::operator<<(std::ostream& out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.grade;
    return out;
}
