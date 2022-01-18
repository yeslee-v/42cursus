//
// Created by Yeshin Lee on 2022/01/16.
//

#include "Brain.hpp"

Brain::Brain() : idx(0) {
    std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain) {
    std::cout << "Copy constructor called" << std::endl;
    *this = brain;
}

Brain& Brain::operator=(const Brain &brain) {
    std::cout << "Assignment copy operator called" << std::endl;
    this->idx = brain.idx;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain: Destructor called" << std::endl;
}

void Brain::setIdea(const std::string idea) {
    this->ideas[idx] = idea;
    idx++;
}

std::string Brain::getIdea(unsigned int idx) const {
    if (this->idx > 100)
    {
        std::cout << "Wrong idx" << std::endl;
        return NULL;
    }
    std::cout << "here is " << this->ideas[idx] << std::endl;
    return this->ideas[idx];
}
