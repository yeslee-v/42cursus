//
// Created by Yeshin Lee on 2021/12/26.
//

#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    return (new Zombie(name));
}
