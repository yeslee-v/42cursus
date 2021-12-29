//
// Created by Yeshin Lee on 2021/12/29.
//

#include "Zombie.hpp"

Zombie::Zombie() { }

Zombie::Zombie(std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
        std::cout << "Vanish " << this->name << std::endl;
}

void Zombie::announce() {
    std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::SetName(std::string name) {
    this->name = name;
}
