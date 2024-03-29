//
// Created by Yeshin Lee on 2022/01/20.
//

#include "Form.hpp"

Form::Form(std::string name, int required, int execute) : name(name) {
    std::cout << this->name << ": default constructor called" << std::endl;
    this->is_signed = NOT_SIGNED;
    this->grade.required = required;
    this->grade.execute = execute;
    if ((this->grade.required < MIN) || (this->grade.execute < MIN))
        throw Bureaucrat::GradeTooLowException();
    else if ((this->grade.required > MAX) || (this->grade.execute > MAX))
        throw Bureaucrat::GradeTooHighException();
}

Form::Form(const Form &form) {
    *this = form;
}

Form& Form::operator=(const Form &form) {
    this->name = form.getName();
    this->is_signed = form.getIsSigned();
    this->grade.required = form.getGradeRequired();
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
    return this->grade.required;
}

int Form::getGradeExecute() const {
    return this->grade.execute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    std::cout << "compare >>> " << bureaucrat.getGrade() << " | " << this->getGradeRequired() << std::endl;
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

const char* Form::NotSignedException::what() const throw() {
    return "Form is NOT signed";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "form's name: " << form.getName() << "\n";
    out << "form's is_signed: " << (form.getIsSigned() ? "SIGNED" : "NOT_SIGNED") << "\n";
    out << "form's gradeRequired: " << form.getGradeRequired() << "\n";
    out << "form's gradeExecute: " << form.getGradeExecute() << "\n";
    return out;
}
