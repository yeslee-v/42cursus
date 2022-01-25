//
// Created by Yeshin Lee on 2022/01/24.
//

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

template<typename T>
void iter(T *arrayAddress, int ArrayLen, void (* func)(T const &)) {
    int i = -1;

    while (++i < ArrayLen) {
        func(arrayAddress[i]);
    }
}

#endif
