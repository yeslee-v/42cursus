//
// Created by Yeshin Lee on 2021/12/26.
//

#include "Zombie.hpp"

int main(void) {
    Zombie* heapZombie;
    Zombie  stackZombie = Zombie("stackChump");

    heapZombie = newZombie("HeapChump");

    heapZombie->announce();
    stackZombie.announce();
    delete heapZombie;
}
