//
// Created by Yeshin Lee on 2021/12/26.
//

#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie* zombie;

    zombie = newZombie(name);
    zombie->announce();
    delete zombie;
}
