//
// Created by Yeshin Lee on 2022/01/15.
//

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << this->type << ": Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
    std::cout << "Copy constructor called" << std::endl;
    *this = wrongAnimal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
    std::cout << "Assignment copy operator called" << std::endl;
    this->type = wrongAnimal.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor called" << std::endl;
}

void WrongAnimal::setType(std::string type) {
    this->type = type;
}

std::string WrongAnimal::getType(void) const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "나는 동물이 아니야!!!!" << std::endl;
}
