//
// Created by Yeshin Lee on 2022/01/22.
//

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cctype> // isprint

class Convert {
public:
    Convert();
    Convert(const Convert& convert);
    Convert& operator=(const Convert& convert);
    ~Convert();

    void ConvertChar(std::string value);
    void ConvertInt(std::string value);
    void ConvertFloat(std::string value);
    void ConvertDouble(std::string value);
};

#endif
