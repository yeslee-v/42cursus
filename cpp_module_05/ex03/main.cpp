//
// Created by Yeshin Lee on 2022/01/18.
//

#include "Intern.hpp"
#include "Form.hpp"

int main(void) {

    Intern someRandomIntern;

    Form* scf;
    Form* rrf;
    Form* ppf;

    std::cout << std::endl;
    try {
        scf = someRandomIntern.makeForm("shrubberyCreation", "Bender");
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        rrf = someRandomIntern.makeForm("robotomyRequest", "Bender");
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        ppf = someRandomIntern.makeForm("presidentialPardon", "Bender");
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    delete scf;
    delete rrf;
    delete ppf;

    return 0;
}
