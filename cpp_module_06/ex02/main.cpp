//
// Created by Yeshin Lee on 2022/01/22.
//

#include "Identify.hpp"

int main() {
    Base* base;

    std::cout << "[Generic Function]" << std::endl;
    base = generate();
    std::cout << base << std::endl;
    std::cout << std::endl;

    std::cout << "[Identify Function using pointer]" << std::endl;
    identify(base);
    std::cout << std::endl;

    std::cout << "[Identify Function using reference]" << std::endl;
    identify(*base);
    return 0;
}
