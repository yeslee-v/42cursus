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
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& bureaucrat);
    Bureaucrat& operator=(const Bureaucrat& bureaucrat);
    ~Bureaucrat();

    std::string getName(void) const;
    int getGrade(void) const;

    void IncrementGrade(void);
    void DecrementGrade(void);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
