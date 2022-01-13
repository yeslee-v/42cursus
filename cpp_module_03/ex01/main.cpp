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
    cula.beRepaired(5);
    frankie.attack(cula.getName());
    zizi.takeDamage(frankie.getHitPoints());
    cula.beRepaired(3);
    std::cout << std::endl;
}
