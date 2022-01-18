//
// Created by Yeshin Lee on 2022/01/15.
//

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* brain;
public:
    Cat();
    Cat(const Cat& cat);
    Cat& operator=(const Cat& cat);
    ~Cat();

    Brain& getBrain(void) const;
    void setBrainIdea(std::string idea);
    std::string getBrainIdea(unsigned int idx) const;

    void makeSound(void) const;
};


#endif
