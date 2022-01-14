//
// Created by Yeshin Lee on 2022/01/14.
//

#include <iostream>
#include "DiamondTrap.hpp"

int main(void) {
    ScavTrap frankie("frankie");
    FragTrap cula("cula");
    DiamondTrap zizi("zizi");
    std::cout << std::endl;

    std::cout << "-------zizi's stack---------" << std::endl;
    std::cout << "Name: " << zizi.getName() << std::endl;
    std::cout << "Hitpoints: " << zizi.getHitPoints() << std::endl;
    std::cout << "Energypoints: " << zizi.getEnergyPoints() << std::endl;
    std::cout << "Attackdamages: " << zizi.getAttackDamage() << std::endl;

    std::cout << std::endl;
    cula.attack(zizi.getName());
    zizi.takeDamage(cula.getHitPoints());
    cula.highFivesGuys();

    std::cout << std::endl;
    zizi.beRepaired(420);
    frankie.attack(cula.getName());
    cula.takeDamage(frankie.getHitPoints());
    frankie.guardGate();
    cula.beRepaired(110);

    std::cout << std::endl;
    zizi.whoAmI();
    std::cout << std::endl;
}
