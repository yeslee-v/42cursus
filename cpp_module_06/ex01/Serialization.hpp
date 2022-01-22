//
// Created by Yeshin Lee on 2022/01/22.
//

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>

typedef struct s_Data {
    int id;
    std::string name;
} Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
