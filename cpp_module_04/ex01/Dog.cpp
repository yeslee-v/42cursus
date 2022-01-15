//
// Created by Yeshin Lee on 2022/01/15.
//

#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << this->type << ": Default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) {
    std::cout << "Copy constructor called" << std::endl;
    *this = dog;
}

Dog& Dog::operator=(const Dog &dog) {
    std::cout << "Assignment copy operator called" << std::endl;
    this->type = dog.getType();
    return *this;
}

Dog::~Dog() {
    std::cout << "Destructor called" << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "멍" << std::endl;
}
