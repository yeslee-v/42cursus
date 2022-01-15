//
// Created by Yeshin Lee on 2022/01/15.
//

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& wrongAnimal);
    WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
    ~WrongAnimal();

    void setType(std::string type);
    std::string getType(void) const;

    void makeSound(void) const;
};


#endif
