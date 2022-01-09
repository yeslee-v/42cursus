//
// Created by Yeshin Lee on 2022/01/07.
//

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "a = " << a << std::endl;
    std::cout << "pre-increment : " << ++a << std::endl;
    std::cout << "post-increment : " << a++ << std::endl;
    std::cout << "pre-decrement : " << --a << std::endl;
    std::cout << "post-decrement : " << a-- << std::endl;

    std::cout << std::endl;
    std::cout << "after a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << std::endl;
    std::cout << "[comparison operators]" << std::endl;
    if (a>b)
        std::cout << "a is bigger than b" << std::endl;
    if (a<b)
        std::cout << "b is bigger than a" << std::endl;
    if (a>=b)
        std::cout << "a is equal or bigger than b" << std::endl;
    if (a<=b)
        std::cout << "b is equal or bigger than a" << std::endl;
    if (a==b)
        std::cout << "a is equal b" << std::endl;
    if (a!=b)
        std::cout << "a is not equal b" << std::endl;

    std::cout << std::endl;
    std::cout << "[arithmetic operators]" << std::endl;
    std::cout << "a + b = " << a+b << std::endl;
    std::cout << "a - b = " << a-b << std::endl;
    std::cout << "a * b = " << a*b << std::endl;
    std::cout << "a / b = " << a/b << std::endl;

    std::cout << "min is " << Fixed::min( a, b ) << std::endl;
    std::cout << "max is " << Fixed::max( a, b ) << std::endl;

    return 0;
}
