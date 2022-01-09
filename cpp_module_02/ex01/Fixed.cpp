//
// Created by Yeshin Lee on 2022/01/07.
//

#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(int raw) { // 정수 -> 고정 소수점으로
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point = raw << Fixed::fractional_bits;
}

Fixed::Fixed(float raw) { // 부동 소수점 -> 고정 소수점으로
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point = roundf(raw * (1 << Fixed::fractional_bits));
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
    return this->fixed_point;
}

void Fixed::setRawBits(int const raw) {
    this->fixed_point = raw << Fixed::fractional_bits;
}

void Fixed::setRawBits(float const raw) {
    this->fixed_point = raw * (1 << Fixed::fractional_bits);
}

int Fixed::toInt(void) const { // 고정 소수점 값 -> 정수 값
    return this->fixed_point >> Fixed::fractional_bits;
}

float Fixed::toFloat(void) const {// 고정 소수점 값 -> 부동 소수점 상수
    return (float)(this->fixed_point) / (1 << Fixed::fractional_bits);
}

// 매개변수의 출력 스트림에 고정 소수점 값의 부동 소수점 삽입
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
