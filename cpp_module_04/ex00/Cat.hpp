//
// Created by Yeshin Lee on 2022/01/15.
//

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : class Animal {
public:
    Cat();
    Cat(type);
    Cat(const Cat& cat);
    Cat& operator=(const Cat& cat);
};


#endif
