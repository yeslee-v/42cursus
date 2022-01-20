//
// Created by Yeshin Lee on 2022/01/20.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("robotomyRequest", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm)
: Form(robotomyRequestForm.target, 72, 45){
    *this = robotomyRequestForm;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm) {
    this->target = robotomyRequestForm.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() {
    return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!(Form::getIsSigned()))
        throw Form::NotSignedException();
    else if (executor.getGrade() > this->getGradeExecute())
        throw Form::GradeTooLowException();
    else if (executor.getGrade() < MIN)
        throw Form::GradeTooLowException();
    else if (executor.getGrade() > MAX)
        throw Form::GradeTooHighException();
    else
    {
        if (rand() % 2)
            std::cout << this->target << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->target << " has been robotomized fail" << std::endl;
    }
}

