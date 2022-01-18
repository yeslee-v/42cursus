//
// Created by Yeshin Lee on 2022/01/18.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    ~Bureaucrat();

    std::string getName(void) const;
    int getGrade(void) const;

    void GradeTooHighException(int grade);
    void GradeTooLowException(int grade);

    Bureaucrat& operator<<(const Bureaucrat& bureaucrat);
};


#endif
