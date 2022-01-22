//
// Created by Yeshin Lee on 2022/01/23.
//

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
#include <exception>
#include <cstdlib> // random, srand

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

enum triplets {
    Aa,
    Bb,
    Cc
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
