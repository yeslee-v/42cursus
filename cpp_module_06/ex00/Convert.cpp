//
// Created by Yeshin Lee on 2022/01/22.
//

#include "Convert.hpp"

Convert::Convert() {}

Convert::Convert(const Convert &convert) {
    *this = convert;
}

Convert& Convert::operator=(const Convert &convert) {
    return *this;
}

Convert::~Convert() {}

void Convert::ConvertChar(std::string value) {
    int c;
    double dc;

    dc = std::stod(value);
    c = static_cast<int>(dc);

    std::cout << "char: ";
    if (isnan(dc) || isinf(dc) || (dc - c))
        std::cout << "impossible" << std::endl;
    else if (dc - c)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(c))
        std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
    else if ((0 <= c) && (c <= 32) || (c == 127)) // ascii but NOT print
        std::cout << "Non displayable" << std::endl;
    else // out of ascii
        std::cout << "impossible" << std::endl;
}

void Convert::ConvertInt(std::string value) {
    int i;
    double dc;

    dc = std::stod(value);

    std::cout << "int: ";
    try {
        i = std::stoi(value);
        if (isnan(dc) || isinf(dc))
            std::cout << "impossible" << std::endl;
        else
            std::cout << i << std::endl;
    }
    catch (std::exception& e) { // out of range
        std::cout << "impossible" << std::endl;
    }
}

void Convert::ConvertFloat(std::string value) {
    float f;

    f = std::stof(value);
    std::cout << "float: ";
    if (isinf(f))
        std::cout << std::showpos << f <<"f" << std::endl;
    else if (isnan(f))
        std::cout << "nanf" << std::endl;
    else
        std::cout << "here: " << f << "f" << std::endl;
}

void Convert::ConvertDouble(std::string value) {
    double d;

    d = std::stod(value);
    std::cout << "double: ";
    if (isinf(d))
        std::cout << std::showpos << d << std::endl;
    else if (isnan(d))
        std::cout << "nan" << std::endl;
    else
        std::cout << "here: " << d << std::endl;
}
