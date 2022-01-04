//
// Created by Yeshin Lee on 2022/01/04.
//

#include "Karen.hpp"

int main(void) {
    Karen person = Karen();
    std::string level;

    std::getline(std::cin, level);
    person.complain(level);

    return 0;
}
