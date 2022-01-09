//
// Created by Yeshin Lee on 2022/01/07.
//

#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed() {
    this->fixed_point = 0;
}

Fixed::Fixed(int raw) { // 정수 -> 고정 소수점으로
    this->fixed_point = raw << Fixed::fractional_bits;
}

Fixed::Fixed(float raw) { // 부동 소수점 -> 고정 소수점으로
    this->fixed_point = roundf(raw * (1 << Fixed::fractional_bits));
}

Fixed::Fixed(const Fixed& fixed) {
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
    this->fixed_point = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return this->fixed_point;
}

void Fixed::setRawBits(int const raw) {
    this->fixed_point = raw << Fixed::fractional_bits;
}

void Fixed::setRawBits(float const raw) {
    this->fixed_point = raw * (1 << Fixed::fractional_bits);
}

/*
 * comparison operators
 */
bool Fixed::operator>(const Fixed& fixed) {
    return this->getRawBits() > fixed.fixed_point;
}

bool Fixed::operator<(const Fixed& fixed) {
    return this->getRawBits() < fixed.fixed_point;
}

bool Fixed::operator>=(const Fixed& fixed) {
    return this->getRawBits() >= fixed.fixed_point;
}

bool Fixed::operator<=(const Fixed& fixed) {
    return this->getRawBits() <= fixed.fixed_point;
}

bool Fixed::operator==(const Fixed& fixed) {
    return this->getRawBits() == fixed.fixed_point;
}

bool Fixed::operator!=(const Fixed& fixed) {
    return this->getRawBits() != fixed.fixed_point;
}

/*
 * arithmetic operators
*/
Fixed Fixed::operator+(const Fixed& fixed) {
    return this->toFloat() + fixed.toFloat();
}

Fixed Fixed::operator-(const Fixed& fixed) {
    return this->toFloat() - fixed.toFloat();
}

Fixed Fixed::operator*(const Fixed& fixed) {
    return this->toFloat() * fixed.toFloat();
}

Fixed Fixed::operator/(const Fixed& fixed) {
    return this->toFloat() / fixed.toFloat();
}

/*
 * increment, decrement operators
*/
Fixed& Fixed::operator++(void) { // 전위 증감 연산자
    ++(this->fixed_point);
    return *this;
}

Fixed Fixed::operator++(int) { // 후위 증감 연산자
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed& Fixed::operator--(void) { // 전위 감소 연산자
    --(this->fixed_point);
    return *this;
}

Fixed Fixed::operator--(int) { // 후위 감소 연산자
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

/*
 * min, max
*/
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return a.fixed_point > b.fixed_point ? b : a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return a.fixed_point > b.fixed_point ? a : b;
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
