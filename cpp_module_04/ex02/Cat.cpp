//
// Created by Yeshin Lee on 2022/01/15.
//

#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain()) {
    this->type = "Cat";
    std::cout << this->type << ": Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat), brain(new Brain) {
    std::cout << "Copy constructor called" << std::endl;
    *this = cat;
}

Cat& Cat::operator=(const Cat &cat) {
    std::cout << "Assignment copy operator called" << std::endl;
    this->type = cat.getType();
    *(this->brain) = cat.getBrain();
    return *this;
}

Cat::~Cat() {
    std::cout << this->type << ": Destructor called" << std::endl;
    delete this->brain;
}

Brain& Cat::getBrain(void) const {
    return *(this->brain);
}

void Cat::setBrainIdea(std::string idea) {
    this->brain->setIdea(idea);
}

std::string Cat::getBrainIdea(unsigned int idx) const {
    return this->brain->getIdea(idx);
}

void Cat::makeSound(void) const {
    std::cout << "냥" << std::endl;
}
