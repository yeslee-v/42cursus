//
// Created by Yeshin Lee on 2021/12/24.
//

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
private:


public:
    std::string	firstName[8];
    std::string	lastName[8];
    std::string	nickname[8];
    std::string	phoneNumber[8];
    std::string	darkestSecret[8];

    void    PrintOpt(void);
    void    PrintLine(int n, char c);
    void    SetPrintValue(std::string str);
    void    PrintValue(char c, std::string str);
};

#endif
