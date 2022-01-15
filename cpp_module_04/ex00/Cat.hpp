//
// Created by Yeshin Lee on 2022/01/15.
//

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& cat);
    Cat& operator=(const Cat& cat);
    ~Cat();

    virtual void makeSound(void) const;
};


#endif
