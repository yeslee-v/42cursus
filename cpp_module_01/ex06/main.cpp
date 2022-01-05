//
// Created by Yeshin Lee on 2022/01/05.
//

#include "Karen.hpp"

int main(int ac, char **av) {
    Karen person = Karen();

    if (ac != 2)
        return 0;
    person.filter(av[1]);

    return 0;
}
