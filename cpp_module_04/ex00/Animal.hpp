//
// Created by Yeshin Lee on 2022/01/15.
//

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& animal);
    Animal& operator=(const Animal& animal);
    ~Animal();

    void setType(std::string type);
    std::string getType(void) const;

    virtual void makeSound(void) const;
};


#endif
