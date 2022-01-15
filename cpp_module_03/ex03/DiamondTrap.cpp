//
// Created by Yeshin Lee on 2022/01/14.
//

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
    ClapTrap::name += "_clap_trap";
    this->hitPoints = FRA_HITPOINTS;
    this->energyPoints = SCAV_ENERGYPOINTS;
    this->attackDamage = FRA_ATTACKDAMAGE;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name), ScavTrap(name), FragTrap(name) {
    std::cout << "[DiamondTrap] Default constructor called" << std::endl;
    ClapTrap::name += "_clap_trap";
    this->name = name;
    this->hitPoints = FRA_HITPOINTS;
    this->energyPoints = SCAV_ENERGYPOINTS;
    this->attackDamage = FRA_ATTACKDAMAGE;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) {
    std::cout << "[DiamondTrap] Copy constructor called" << std::endl;
    *this = diamondTrap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
    std::cout << "[DiamondTrap] Assignation operator called" << std::endl;
    ClapTrap::name = diamondTrap.ClapTrap::getName();
    this->name = diamondTrap.getName();
    this->hitPoints = diamondTrap.getHitPoints();
    this->energyPoints = diamondTrap.getEnergyPoints();
    this->attackDamage = diamondTrap.getAttackDamage();
    return *this;
}

std::string DiamondTrap::getName(void) const {
    return this->name;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "[DiamondTrap] Destructor called" << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount) {
    std::cout << "[DiamondTrap] " << this->name << " take " << amount << " points of damage!" << std::endl;
    this->attackDamage += amount;
    if (this->attackDamage > this->energyPoints)
        std::cout << "[DiamondTrap] " << this->name << " died.." << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
    std::cout << "[DiamondTrap] " << this->name << " is repaired " << amount << std::endl;
    this->energyPoints += amount;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "I'm " << this->name << " in DiamondTrap!" << std::endl;
    std::cout << "I'm " << ClapTrap::getName() << " in ClapTrap!" << std::endl;
}
