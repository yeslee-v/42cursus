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

class Bureaucrat : public std::exception {
private:
    std::string name;
    int grade;
public:
    Bureaucrat(std::string name);
    ~Bureaucrat();

    void setGrade(unsigned int score);

    std::string getName(void) const;
    int getGrade(void) const;

    void GradeTooHighException(void);
    void GradeTooLowException(void);

//    std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
};


#endif
