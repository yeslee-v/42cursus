//
// Created by Yeshin Lee on 2022/01/14.
//

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

# define FRA_HITPOINTS 100;
# define SCAV_ENERGYPOINTS 50;
# define FRA_ATTACKDAMAGE 100;

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string name;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& diamondTrap);
    DiamondTrap& operator=(const DiamondTrap& diamondTrap);
    ~DiamondTrap();

    std::string getName(void) const;

    using ScavTrap::attack;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void whoAmI(void);
};


#endif
