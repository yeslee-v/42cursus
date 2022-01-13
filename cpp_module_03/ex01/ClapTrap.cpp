//
// Created by Yeshin Lee on 2022/01/10.
//

#include "ClapTrap.hpp"

/*
 * OCCF
*/
ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name) :
    name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
    std::cout << "ClapTrap: Copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) {
    std::cout << "ClapTrap: Assignation operator called" << std::endl;
    this->name = clapTrap.getName();
    this->hitPoints = clapTrap.getHitPoints();
    this->energyPoints = clapTrap.getEnergyPoints();
    this->attackDamage = clapTrap.getAttackDamage();
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap: Destructor called" << std::endl;
}

/*
 * setter, getter
*/
void ClapTrap::setName(std::string name) {
    this->name = name;
}

std::string ClapTrap::getName(void) const {
    return this->name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
    this->hitPoints = hitPoints;
}

unsigned int ClapTrap::getHitPoints(void) const {
    return this->hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    this->energyPoints = energyPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
    return this->energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
    this->attackDamage = attackDamage;
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return this->attackDamage;
}

/*
 * doing what
*/
void ClapTrap::attack(std::string const& target) {
    std::cout << "ClapTrap " << this->name << " attack " << target << " causing " << this->hitPoints << " points of damage!" << std::endl;
    this->hitPoints += this->hitPoints;
    std::cout << this->name << "'s hitPoint is " << this->hitPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->name << " take " << amount << " points of damage!" << std::endl;
    this->attackDamage += amount;
    if (this->attackDamage > this->energyPoints)
        std::cout << this->name << " died.." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << this->name << " is repaired " << amount << std::endl;
    this->energyPoints += amount;
}
