//
// Created by Yeshin Lee on 2022/01/20.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("shrubberyCreation", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm)
: Form(shrubberyCreationForm.target, 145, 137){
    *this = shrubberyCreationForm;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm) {
    this->target = shrubberyCreationForm.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() {
    return this->target;
}

void ShrubberyCreationForm::DrawAsciiTree(std::ofstream& writeFile) const {
    writeFile << "    *    " << std::endl;
    writeFile << "    @    " << std::endl;
    writeFile << "   @@#   " << std::endl;
    writeFile << "  @#@@@  " << std::endl;
    writeFile << " #@@#@#@ " << std::endl;
    writeFile << "   :::   " << std::endl;
    writeFile << "  =====  " << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
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
        std::ofstream writeFile;
        std::string filename = this->target + "_shrubbery";

        writeFile.open(filename);
        if (!(writeFile))
            std::cout << "DO NOT open for write: " << filename << std::endl;
        else
        {
            DrawAsciiTree(writeFile);
            writeFile.close();
        }
    }
}
