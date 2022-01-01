//
// Created by Yeshin Lee on 2021/12/30.
//

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
: name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void    HumanA::attack(void) {
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}
