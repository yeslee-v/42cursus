//
// Created by Yeshin Lee on 2022/01/15.
//

#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain()) {
    this->type = "Dog";
    std::cout << this->type << ": Default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog), brain(new Brain()) {
    std::cout << "Copy constructor called" << std::endl;
    *this = dog;
}

Dog& Dog::operator=(const Dog &dog) {
    std::cout << "Assignment copy operator called" << std::endl;
    this->type = dog.getType();
    *(this->brain) = dog.getBrain();
    return *this;
}

Dog::~Dog() {
    std::cout << this->type << ": Destructor called" << std::endl;
    delete this->brain;
}

Brain& Dog::getBrain(void) const {
    return *(this->brain);
}

void Dog::setBrainIdea(std::string idea) {
    this->brain->setIdea(idea);
}

std::string Dog::getBrainIdea(unsigned int idx) const {
    return this->brain->getIdea(idx);
}

void Dog::makeSound(void) const {
    std::cout << "멍" << std::endl;
}
