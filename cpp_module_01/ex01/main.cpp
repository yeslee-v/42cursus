//
// Created by Yeshin Lee on 2021/12/29.
//

#include "Zombie.hpp"

int main(void) {
    int     n;

    std::cout << "How many zombies are there? ";
    std::cin >> n;
    std::cout << std::endl;
    Zombie* zombies = zombieHorde(n, "HeapChumps");

    for (int i = 0; i < n; i++)
        zombies[i].announce();
    delete[] zombies;
    return (0);
}
