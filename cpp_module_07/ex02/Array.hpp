//
// Created by Yeshin Lee on 2022/01/26.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<typename T>
class Array {
private:
    int n;
    T* arr;
public:
    Array() : n(0), arr(new T) {
        std::cout << "Default constructor called" << std::endl;
    };
    Array(unsigned int n) : n(n), arr(new T[n]) {
        std::cout << "Default constructor having parameter n called" << std::endl;
    };
    Array(const Array& array) {
        std::cout << "Copy constructor called" << std::endl;
        arr = new T[array.n];
        *this = array;
    }
    Array& operator=(const Array& array) {
        std::cout << "Assignment copy operator called" << std::endl;
        n = array.n;
        for (int i = 0; i < n; i++)
            arr[i] = array.arr[i];

        return *this;
    }
    ~Array() {
        std::cout << "Destructor called" << std::endl;
        delete[] arr;
    }

    T& operator[](unsigned int idx) {
       if (this->n <= idx)
           throw std::exception();
       return this->arr[idx];
    }
    int size() {
        return n;
    }
};

#endif
