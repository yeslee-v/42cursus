//
// Created by Yeshin Lee on 2022/01/15.
//

#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << this->type << ": Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) {
    std::cout << "Copy constructor called" << std::endl;
    *this = cat;
}

Cat& Cat::operator=(const Cat &cat) {
    std::cout << "Assignment copy operator called" << std::endl;
    this->type = cat.getType();
    return *this;
}

Cat::~Cat() {
    std::cout << "Destructor called" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "냥" << std::endl;
}
