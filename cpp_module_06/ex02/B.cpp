//
// Created by Yeshin Lee on 2022/01/22.
//

#include "B.hpp"

B::B() {}

B::B(const B &b) {
    *this = b;
}

B& B::operator=(const B &b) {
    return *this;
}

B::~B() {}
