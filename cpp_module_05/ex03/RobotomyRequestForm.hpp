//
// Created by Yeshin Lee on 2022/01/20.
//

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Form.hpp"

class RobotomyRequestForm : public Form {
private:
    std::string target;
public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& robotomyRequestForm);
    ~RobotomyRequestForm();

    std::string getTarget();

    void execute(Bureaucrat const & executor) const;
};


#endif
