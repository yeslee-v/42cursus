//
// Created by Yeshin Lee on 2022/01/06.
//

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int num;
    const int i;
public:
    Fixed();
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
