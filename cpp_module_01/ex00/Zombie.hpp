//
// Created by Yeshin Lee on 2021/12/26.
//

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class   Zombie {
private:
        std::string name;

public:
        Zombie(std::string name);
        ~Zombie();

        void announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
