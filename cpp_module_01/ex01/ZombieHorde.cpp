//
// Created by Yeshin Lee on 2021/12/29.
//

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* zombies = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        std::stringstream str;
        str << i;
        zombies[i].SetName(name + "_" + str.str());
    }

    return (zombies);
}
