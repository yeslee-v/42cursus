#include "contact.hpp"

void PrintValue(char c, std::string str) {
    std::cout << "|" << std::setfill(c) << std::setw(10) << str;
}

void SetPrintValue(std::string str) {               // 값 출력할 때만
    std::string value = str.substr(0, 9);
    if (str.length() > 9)
        value.append(".");
    PrintValue(' ', value);
}

void PrintOpt(void) {
    PrintValue(' ', "index");
    PrintValue(' ', "first name");
    PrintValue(' ', "last name");
    PrintValue(' ', "nickname");
    std::cout << "|" << std::endl;
}

void PrintLine(int n, char c) {
    int i = 4;

    std::cout << "|" << std::setfill(c) << std::setw(n);
    while (--i)
        std::cout << "|" << std::setw(n);
    std::cout << "|" << std::endl;
}
