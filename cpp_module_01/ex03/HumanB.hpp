//
// Created by Yeshin Lee on 2021/12/30.
//

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    Weapon weapon;
    std::string name;
public:
    HumanB();
    HumanB(std::string name);
    ~HumanB();

    void setHumanB(std::string name);
    void setWeapon(Weapon weapon);
    std::string getHumanB(void);

    static void attack(void);
};

#endif
