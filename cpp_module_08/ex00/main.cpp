//
// Created by Yeshin Lee on 2022/01/29.
//

#include "easyfind.hpp"

int main() {
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    try {
        std::cout << easyfind(vec, 20) << std::endl;
        std::cout << easyfind(vec, 40) << std::endl;
        std::cout << easyfind(vec, 10) << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;

}
