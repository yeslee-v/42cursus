//
// Created by Yeshin Lee on 2021/12/30.
//

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
    Weapon weapon;
    std::string name;
public:
    HumanA();
    HumanA(Weapon weapon);
    ~HumanA();

    void setHumanA(std::string name);
    std::string getHumanA(void);

    static void attack(void);
};


#endif
