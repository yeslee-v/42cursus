//
// Created by Yeshin Lee on 2021/12/26.
//

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
        std::cout << "Vanish " << this->name << std::endl;
}

void Zombie::announce() {
    std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
