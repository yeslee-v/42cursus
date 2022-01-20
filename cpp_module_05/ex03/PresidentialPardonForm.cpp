//
// Created by Yeshin Lee on 2022/01/20.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("presidentialPardon", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm)
: Form(presidentialPardonForm.target, 25, 5){
    *this = presidentialPardonForm;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm) {
    this->target = presidentialPardonForm.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() {
    return this->target;
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!(Form::getIsSigned()))
        throw Form::NotSignedException();
    else if (executor.getGrade() > this->getGradeExecute())
        throw Form::GradeTooLowException();
    else if (executor.getGrade() < MIN)
        throw Form::GradeTooLowException();
    else if (executor.getGrade() > MAX)
        throw Form::GradeTooHighException();
    else
        std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}


