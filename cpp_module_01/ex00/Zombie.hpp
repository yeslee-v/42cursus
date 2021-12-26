//
// Created by Yeshin Lee on 2021/12/26.
//

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string*    name;
    int             size;
    int             used;

public:
    Zombie();
    ~Zombie();

    void SetName(std::string str);
    void GetName(int idx);
    void announce(void);
    void randomChump(std::string name);
    Zombie* newZombie(std::string name);

};


#endif
