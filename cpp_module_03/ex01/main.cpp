//
// Created by Yeshin Lee on 2022/01/10.
//

#include "ScavTrap.hpp"

int main(void) {
    ClapTrap zizi("zizi");
    ScavTrap cula("cula");
    ScavTrap frankie("frankie");

    std::cout << std::endl;
    zizi.attack(cula.getName());
    cula.guardGate();

    std::cout << std::endl;
    frankie.attack(cula.getName());
    zizi.takeDamage(frankie.getHitPoints());
    std::cout << std::endl;
}
