//
// Created by Yeshin Lee on 2022/01/20.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>

#include "Form.hpp"

class PresidentialPardonForm : public Form {
private:
    std::string target;
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& presidentialPardonForm);
    ~PresidentialPardonForm();

    std::string getTarget();

    void execute(Bureaucrat const & executor) const;
};


#endif
