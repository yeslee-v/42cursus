#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

enum Info {
    FIRSTNAME,
    LASTNAME,
    NICKNAME,
    PHONENUMBER,
    DARKESTSECRET,
};

class Contact {
private:
    std::string contacts[5];

public:
    void SetValue(std::string str[5]);

    std::string GetValue(int idx);
};

#endif
