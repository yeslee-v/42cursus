//
// Created by Yeshin Lee on 2022/01/06.
//

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int fixed_point;
    static const int fractional_bits;
public:
    Fixed();
    Fixed(const Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
