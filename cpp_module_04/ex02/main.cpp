//
// Created by Yeshin Lee on 2022/01/15.
//

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    {
        int i = 20;
        Dog* dog = new Dog();
        Cat* cat = new Cat();

        std::cout << std::endl;
        dog->makeSound();
        cat->makeSound();

        delete dog;//should not create a leak
        delete cat;
        while (--i > -1)
            std::cout << "-";
        std::cout << std::endl;
    }
    int num = 4;
    const Animal* animal[num];

    for (int i = 0; i < num; i++)
    {
        if (i % 2)
        {
            animal[i] = new Dog();
            std::cout << "animal[" << i << "] type: " << animal[i]->getType() << std::endl;
            std::cout << "animal[" << i << "]: address " << animal[i] << std::endl;
            std::cout << std::endl;
        }
        else
        {
            animal[i] = new Cat();
            std::cout << "animal[" << i << "] type: " << animal[i]->getType() << std::endl;
            std::cout << "animal[" << i << "] address: " << animal[i] << std::endl;
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
    for (int i = 0; i < num; i++)
        delete animal[i];
}
