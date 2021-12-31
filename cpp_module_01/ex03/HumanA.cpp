//
// Created by Yeshin Lee on 2021/12/30.
//

#include "HumanA.hpp"

HumanA HumanA() { }

HumanA HumanA(Weapon weapon) {
    this->weapon = weapon;
}

HumanA ~HumanA() { }

void HumanA::setHumanA(std::string name, Weapon weapon) {
    this->name = name;
    this->weapon = weapon;
}

std::string HumanA::getHumanA(void) {
    return name;
}

static void    attack(void) {
    std::string typeA = Weapon::getType();
    std::string nameA = HumanA::getHumanA();

    std::cout << nameA << " attacks with his " << typeA << std::endl;
}
