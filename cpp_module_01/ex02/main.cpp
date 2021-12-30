//
// Created by Yeshin Lee on 2021/12/30.
//

#include <iostream>

int main(void) {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "[ Print ADDRESS ]" << std::endl;
    std::cout << "brain : " << &brain << std::endl;
    std::cout << "stringPTR : " << stringPTR << std::endl;
    std::cout << "stringREF : " << &stringREF << std::endl;

    std::cout << std::endl;
    std::cout << "[ Print STRING ]" << std::endl;
    std::cout << "brain : " << brain << std::endl;
    std::cout << "stringPTR : " << *stringPTR << std::endl;
    std::cout << "stringREF : " << stringREF << std::endl;
    return (0);
}
