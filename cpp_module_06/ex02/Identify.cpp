//
// Created by Yeshin Lee on 2022/01/23.
//

#include "Identify.hpp"

Base* generate(void) {
    srand(time(NULL));
    int i = rand() % 3;

    std::cout << "random number is " << i << std::endl;
    switch (i) {
        case Aa :
            std::cout << "A created: ";
            return new A;
        case Bb :
            std::cout << "B created: ";
            return new B;
        case Cc :
            std::cout << "C created: ";
            return new C;
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) // 안만들어지면 NULL 반환
        std::cout << "A created" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B created" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C created" << std::endl;
    else
        std::cout << "NULL" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A created: " << &a << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "A: Caught bad cast" << std::endl;
    }

    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B created: " << &b << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "B: Caught bad cast" << std::endl;
    }

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C created: " << &c << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "C: Caught bad cast" << std::endl;
    }
}
