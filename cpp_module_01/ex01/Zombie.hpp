//
// Created by Yeshin Lee on 2021/12/29.
//

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <sstream>

class   Zombie {
private:
        std::string name;

public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();

        void announce(void);
        void SetName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
