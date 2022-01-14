//
// Created by Yeshin Lee on 2022/01/10.
//

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
public:
    ClapTrap(std::string Name);
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap& operator=(const ClapTrap& clapTrap);
    ~ClapTrap();

    void setName(std::string name);
    std::string getName(void) const;
    void setHitPoints(unsigned int hitPoints);
    unsigned int getHitPoints() const;
    void setEnergyPoints(unsigned int energyPoints);
    unsigned int getEnergyPoints(void) const;
    void setAttackDamage(unsigned int attackDamage);
    unsigned int getAttackDamage(void) const;

    void attack(std::string const& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};


#endif
