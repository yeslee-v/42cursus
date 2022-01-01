//
// Created by Yeshin Lee on 2021/12/30.
//

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: name(name) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void    HumanB::attack(void) {
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}
