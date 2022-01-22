//
// Created by Yeshin Lee on 2022/01/22.
//

#include "A.hpp"

A::A() {}

A::A(const A &a) {
    *this = a;
}

A& A::operator=(const A &a) {
    return *this;
}

A::~A() {}
