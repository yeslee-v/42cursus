//
// Created by Yeshin Lee on 2022/01/06.
//

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int raw;
    int bits;
public:
    Fixed();
    Fixed(const Fixed&);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
