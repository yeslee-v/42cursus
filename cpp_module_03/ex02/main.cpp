//
// Created by Yeshin Lee on 2022/01/14.
//

#include "FragTrap.hpp"

int main(void) {
    ClapTrap zizi("zizi");
    FragTrap cula("cula");
    FragTrap frankie("frankie");

    std::cout << std::endl;
    zizi.attack(cula.getName());
    cula.takeDamage(zizi.getHitPoints());

    std::cout << std::endl;
    cula.beRepaired(5);
    frankie.attack(cula.getName());
    zizi.takeDamage(frankie.getHitPoints());
    frankie.highFivesGuys();
    std::cout << std::endl;
}
