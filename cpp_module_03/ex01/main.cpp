//
// Created by Yeshin Lee on 2022/01/10.
//

#include "ClapTrap.hpp"

int main(void) {
    std::string const cula;

    ClapTrap zizi = ClapTrap("zizi");
    ClapTrap kongkong = ClapTrap("kongkong");
    ClapTrap kebi = ClapTrap("kebi");

    std::cout << std::endl;
    zizi.attack(kebi.getName());
    kebi.takeDamage(zizi.getHitPoints());

    std::cout << std::endl;
    kebi.beRepaired(5);
    kongkong.attack(kebi.getName());
    zizi.takeDamage(kongkong.getHitPoints());
    kebi.beRepaired(3);
    std::cout << std::endl;
}
