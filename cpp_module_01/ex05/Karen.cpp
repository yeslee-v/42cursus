//
// Created by Yeshin Lee on 2022/01/04.
//

#include "Karen.hpp"

Karen::Karen() {
    list[DEBUG].level = "DEBUG";
    list[DEBUG].p = &Karen::debug;

    list[INFO].level = "INFO";
    list[INFO].p = &Karen::info;

    list[WARNING].level = "WARNING";
    list[WARNING].p = &Karen::warning;

    list[ERROR].level = "ERROR";
    list[ERROR].p = &Karen::error;
}

Karen::~Karen() {}

void Karen::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl << "I love to get this!" << std::endl;
}

void Karen::info(void) {
    std::cout << "[ INFO ]" << std::endl << "If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void) {
    std::cout << "[ WARNING ]" << std::endl << "This is a WARNING." << std::endl;
}

void Karen::error(void) {
    std::cout << "[ ERROR ]" << std::endl << "I want to speak to the manager now." << std::endl;
}

void    Karen::complain(std::string level) {

    for (int i = 0; i < 4; i++) {
        if (list[i].level == level)
            return (this->*list[i].p)();
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
