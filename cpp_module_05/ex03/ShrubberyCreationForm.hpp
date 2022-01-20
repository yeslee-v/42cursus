//
// Created by Yeshin Lee on 2022/01/20.
//

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
private:
    std::string target;
public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreationForm);
    ~ShrubberyCreationForm();

    std::string getTarget();

    void DrawAsciiTree(std::ofstream& writeFile) const;
    void execute(Bureaucrat const & executor) const;
};


#endif
