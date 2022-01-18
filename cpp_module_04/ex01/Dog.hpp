//
// Created by Yeshin Lee on 2022/01/15.
//

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain;
public:
    Dog();
    Dog(const Dog& dog);
    Dog& operator=(const Dog& dog);
    ~Dog();

    Brain& getBrain(void) const;
    void setBrainIdea(std::string idea);
    std::string getBrainIdea(unsigned int idx) const;

    void makeSound(void) const;
};


#endif
