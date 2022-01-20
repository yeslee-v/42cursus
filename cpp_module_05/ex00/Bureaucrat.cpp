//
// Created by Yeshin Lee on 2022/01/18.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
    std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) {
    *this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
    this->name = bureaucrat.getName();
    this->grade = bureaucrat.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "destructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::IncrementGrade() {
    ++(this->grade);
    if (this->grade > MAX)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::DecrementGrade() {
    --(this->grade);
    if (this->grade < MIN)
        throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "[Grade is too high]";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "[Grade is too low]";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &bureaucrat) {
    out << "bureaucrat's name: " << bureaucrat.getName() << "\n";
    out << "bureaucrat's grade: " << bureaucrat.getGrade() << "\n";
    return out;
}
