//
// Created by Yeshin Lee on 2022/01/12.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "[ScavTrap] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
    std::cout << "[ScavTrap] Copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap) {
    std::cout << "[ScavTrap] Assignation operator called" << std::endl;
    this->name = scavTrap.getName();
    this->hitPoints = scavTrap.getHitPoints();
    this->energyPoints = scavTrap.getEnergyPoints();
    this->attackDamage = scavTrap.getAttackDamage();
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "[ScavTrap] Destructor called" << std::endl;
}

unsigned int ScavTrap::getEnergyPoints(void) const {
    return this->energyPoints;
}

void ScavTrap::attack(std::string const& target) {
    std::cout << "[ScavTrap] " << this->name << " attack " << target << " causing " << this->hitPoints << " points of damage!" << std::endl;
    this->hitPoints += this->hitPoints;
    std::cout << "[ScavTrap] " << this->name << "'s hitPoint is " << this->hitPoints << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
    std::cout << "[ScavTrap] " << this->name << " take " << amount << " points of damage!" << std::endl;
    this->attackDamage += amount;
    if (this->attackDamage > this->energyPoints)
        std::cout << "[ScavTrap] " << this->name << " died.." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    std::cout << "[ScavTrap] " << this->name << " is repaired " << amount << std::endl;
    this->energyPoints += amount;
}

void ScavTrap::guardGate(void) {
    std::cout << "[ScavTrap] " << this->name << " is into the Gate keeper mode" << std::endl;
}
