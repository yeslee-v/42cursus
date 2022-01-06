//
// Created by Yeshin Lee on 2022/01/06.
//

#include "Fixed.hpp"

Fixed::Fixed() {
    this->raw = 0;
    this->bits = 8;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& origin) {
    this->raw = origin.raw;
    this->bits = 8;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
    std::cout << "Assignation operator called" << std::endl;
    std::cout << "getRawBits member function called" << std::endl;
    this->raw = fixed.raw;
    this->bits = 8;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->raw);
}

void Fixed::setRawBits(int const raw) {
    this->raw = raw;
}
