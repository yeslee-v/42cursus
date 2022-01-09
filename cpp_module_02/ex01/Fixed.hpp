//
// Created by Yeshin Lee on 2022/01/07.
//

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int fixed_point;
    static const int fractional_bits;
public:
    Fixed();
    Fixed(const Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();

    Fixed(int raw);
    Fixed(float raw);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    void setRawBits(float const raw);

    int toInt(void) const;
    float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
