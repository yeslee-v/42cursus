//
// Created by Yeshin Lee on 2022/01/06.
//

#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
    std::cout << "Assignation operator called" << std::endl;
    this->fixed_point = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point;
}

void Fixed::setRawBits(int const raw) {
    this->fixed_point = raw << Fixed::fractional_bits;
}
