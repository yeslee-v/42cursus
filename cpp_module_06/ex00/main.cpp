//
// Created by Yeshin Lee on 2022/01/21.
//

#include "Convert.hpp"

void TypeCasting(std::string value) {
    Convert convert;

    convert.ConvertChar(value);
    convert.ConvertInt(value);
    convert.ConvertFloat(value);
    convert.ConvertDouble(value);
}

int main(int ac, char **av) {
    std::string value;

    std::cout << std::fixed;
    std::cout.precision(1);

    if (ac != 2)
    {
        std::cerr << "Invalid ac" << std::endl;
        return -1;
    }
    try {
        value = static_cast<std::string>(av[1]);
        TypeCasting(value);
    }
    catch (std::exception& e) {
        std::cout << "Invalid av" << std::endl;
    }

    return 0;
}
