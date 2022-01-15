//
// Created by Yeshin Lee on 2022/01/15.
//

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << this->type << ": Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) {
    std::cout << "Copy constructor called" << std::endl;
    *this = wrongCat;
}

WrongCat& WrongCat::operator=(const WrongCat &wrongCat) {
    std::cout << "Assignment copy operator called" << std::endl;
    this->type = wrongCat.type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Destructor called" << std::endl;
}
