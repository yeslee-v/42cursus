//
// Created by Yeshin Lee on 2022/01/15.
//

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : class Animal {
public:
    Dog();
    Dog(type);
    Dog(const Dog& dog);
    Dog& operator=(const Dog& dog);
};


#endif
