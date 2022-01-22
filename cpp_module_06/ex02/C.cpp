//
// Created cy Yeshin Lee on 2022/01/22.
//

#include "C.hpp"

C::C() {}

C::C(const C &c) {
    *this = c;
}

C& C::operator=(const C &c) {
    return *this;
}

C::~C() {}
