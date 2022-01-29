//
// Created by Yeshin Lee on 2022/01/22.
//

#include <iostream>

#include "Serialization.hpp"

int main() {
    Data info;
    uintptr_t serialization_info;
    Data* deserialization_info ;

    info.id = 1;
    info.name = "yeslee";

    serialization_info = serialize(&info);
    std::cout << "serialization: " << serialization_info << std::endl;

    deserialization_info =  deserialize(serialization_info);
    std::cout << "deserialization: " << deserialization_info->name << std::endl;
    std::cout << "deserialization: " << deserialization_info->id << std::endl;
}
