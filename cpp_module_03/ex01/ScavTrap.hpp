//
// Created by Yeshin Lee on 2022/01/12.
//

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : ClapTrap {
private:
public:
    ScavTrap();
    ScavTrap(const ScavTrap& scavTrap);
    ScavTrap& operator(const ScavTrap& scavTrap);
    ~ScavTrap();

    void guardGate(void);
};


#endif
