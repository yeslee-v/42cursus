//
// Created by Yeshin Lee on 2022/01/18.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

enum range {
    MIN = 1,
    MAX = 150
};

class Bureaucrat {
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    ~Bureaucrat();

    std::string getName(void) const;
    int getGrade(unsigned int score) const;

    void GradeTooHighException(void);
    void GradeTooLowException(void);

    std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
};


#endif
