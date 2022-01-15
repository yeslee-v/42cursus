//
// Created by Yeshin Lee on 2022/01/15.
//

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << this->type << ": Default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) {
    std::cout << "Copy constructor called" << std::endl;
    *this = animal;
}

Animal& Animal::operator=(const Animal &animal) {
    std::cout << "Assignment copy operator called" << std::endl;
    this->type = animal.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Destructor called" << std::endl;
}

void Animal::setType(std::string type) {
    this->type = type;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound(void) const {
   std::cout << "동물이 소리를 낸다" << std::endl;
}
