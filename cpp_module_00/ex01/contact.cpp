#include "contact.hpp"

void Contact::SetValue(std::string str[5]) {
    int i = -1;

    while ((++i) < 5)
        contacts[i] = str[i];
}

std::string Contact::GetValue(int idx) {
    return (contacts[idx]);
}
