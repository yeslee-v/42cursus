//
// Created by Yeshin Lee on 2021/12/26.
//

#include "Zombie.hpp"

Zombie::Zombie() {
    // 초기화
}

Zombie::~Zombie() {
    // Zombie의 이름을 포함한 debugging message 추가
}

void Zombie::SetName(std::string str) {
    name = str;
}

void Zombie::GetName(int idx) {
    return (name[idx]);
}

void Zombie::announce() {
    // <name> BraiiiiiiinnnzzzZ...
    std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}
