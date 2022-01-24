//
// Created by Yeshin Lee on 2022/01/24.
//

#include "iter.hpp"

void callEachArray(int a[4]) {
    for (int i = 0; i < 4; i++)
        std::cout << a[i] << std::endl;
}

int main() {
    int array[4] = {3, 5, 7, 8};

    ::iter(array, 4, callEachArray(array));

    return 0;
}
