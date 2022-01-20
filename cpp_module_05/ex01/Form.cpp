//
// Created by Yeshin Lee on 2022/01/20.
//

#include "Form.hpp"

Form::Form(std::string name, int sign, int execute) : name(name) {
    std::cout << this->name << ": default constructor called" << std::endl;
    this->is_signed = NOT_SIGNED;
    this->grade.sign = sign;
    this->grade.execute = execute;
    if ((this->grade.sign < MIN) || (this->grade.execute < MIN))
        throw Bureaucrat::GradeTooLowException();
    else if ((this->grade.sign > MAX) || (this->grade.execute > MAX))
        throw Bureaucrat::GradeTooHighException();
}

Form::Form(const Form &form) {
    *this = form;
}

Form& Form::operator=(const Form &form) {
    this->name = form.getName();
    this->is_signed = form.getIsSigned();
    this->grade.sign = form.getGradeRequired();
    this->grade.execute = form.getGradeExecute();
    return *this;
}

Form::~Form() {
    std::cout << this->name << ": destructor called" << std::endl;
}

std::string Form::getName() const {
    return this->name;
}

int Form::getIsSigned() const {
    return this->is_signed;
}

int Form::getGradeRequired() const {
    return this->grade.sign;
}

int Form::getGradeExecute() const {
    return this->grade.execute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() < this->getGradeRequired())
        this->is_signed = SIGNED;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form's Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form's Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "form's name: " << form.getName() << "\n";
    out << "form's is_signed: " << (form.getIsSigned() ? "SIGNED" : "NOT_SIGNED") << "\n";
    out << "form's gradeRequired: " << form.getGradeRequired() << "\n";
    out << "form's gradeExecute: " << form.getGradeExecute() << "\n";
    return out;
}
