//
// Created by Yeshin Lee on 2021/12/30.
//

#include "HumanB.hpp"

HumanB HumanB() {}

HumanB HumanB(std::string name) {
    this->name = name;
}

HumanB ~HumanB() {}

void HumanB::setHumanB(std::string name) {
    this->name = name;
}

void HumanB::setWeapon(Weapon weapon) {
    this->weapon = weapon;
}

std::string HumanB::getHumanB(void) {
    return name;
}

static void    attack(void) {
    std::string typeB = Weapon::getType();
    std::string nameB = HumanB::getHumanB();

    std::cout << nameB << " attacks with his " << typeB << std::endl;
}

