//
// Created by Yeshin Lee on 2021/12/30.
//

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
: type(type) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string type) {
    this->type = type;
}

const std::string& Weapon::getType(void) {
    return this->type;
}
