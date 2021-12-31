//
// Created by Yeshin Lee on 2021/12/30.
//

#include "Weapon.hpp"

Weapon Weapon(std::string type) {
    this->type = type;
}

Weapon ~Weapon() {}

void SetType(std::string type) {
    this->type = type;
}

const std::string GetType(void) {
    return &type;
}
