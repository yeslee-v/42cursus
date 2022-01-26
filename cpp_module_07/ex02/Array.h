//
// Created by Yeshin Lee on 2022/01/26.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<typename T>
class Array {
public:
    Array();
    Array(unsigned int n) { return new T[n]};
    void size();
}

#endif
