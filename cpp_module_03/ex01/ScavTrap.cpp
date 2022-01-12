//
// Created by Yeshin Lee on 2022/01/12.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :
    name(name), hitPoints(100), energyPoints(50), attackDamage(20) {
    std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
    std::cout << "ScavTrap: Copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap) {
    std::cout << "ScavTrap: Assignation operator called" << std::endl;
    this->name = ScavTrap.getName();
    this->hitPoints = ScavTrap.getHitPoints();
    this->energyPoints = ScavTrap.getEnergyPoints();
    this->attackDamage = ScavTrap.getAttackDamage();
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: Destructor called" << std::endl;
}