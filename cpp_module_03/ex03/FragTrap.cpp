//
// Created by Yeshin Lee on 2022/01/14.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "[FragTrap] Default constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 100;
}

FragTrap::FragTrap(const FragTrap &fragTrap) {
    std::cout << "[FragTrap] Copy constructor called" << std::endl;
    *this = fragTrap;
}

FragTrap& FragTrap::operator=(const FragTrap &fragTrap) {
    std::cout << "[FragTrap] Assignation operator called" << std::endl;
    this->name = fragTrap.getName();
    this->hitPoints = fragTrap.getHitPoints();
    this->energyPoints = fragTrap.getEnergyPoints();
    this->attackDamage = fragTrap.getAttackDamage();
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "[FragTrap] Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "[FragTrap] " << this->name << " says, Let's highfive!" << std::endl;
}