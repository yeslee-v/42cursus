//
// Created by Yeshin Lee on 2022/01/15.
//

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const WrongCat caramel;

    std::cout << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << caramel.getType() << " " << std::endl;

    std::cout << std::endl;
    animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    caramel.makeSound();

    std::cout << std::endl;
    delete animal;
    delete dog;
    delete cat;
}
