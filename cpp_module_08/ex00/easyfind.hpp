//
// Created by Yeshin Lee on 2022/01/29.
//

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
T easyfind(std::vector<T> container, int value) {
    typename std::vector<T>::iterator itr;

    itr = std::find(container.begin(), container.end(), value);
    if (itr == container.end())
        throw std::exception();
    return std::distance(container.begin(), itr);
}

#endif
