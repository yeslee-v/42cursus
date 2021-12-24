/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:18:36 by yeslee            #+#    #+#             */
/*   Updated: 2021/12/15 21:18:09 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Phonebook::AddInfo(int idx) {
    Contact contact;

    std::cout << "idx is " << idx << std::endl;
    std::cout << "first name : ";
    std::getline(std::cin, contact.firstName[idx]);
    std::cout << "last name : ";
    std::getline(std::cin, contact.lastName[idx]);
    std::cout << "nickname : ";
    std::getline(std::cin, contact.nickname[idx]);
    std::cout << "phone number : ";
    std::getline(std::cin, contact.phoneNumber[idx]);
    std::cout << "darkest secret : ";
    std::getline(std::cin, contact.darkestSecret[idx]);
    if (cnt < 8)
        cnt++;
}

void Phonebook::SearchInfo(int base) {
    int inputIdx;

    if (base == 0)
    {
        std::cout << "Phonebook is empty" << std::endl;
        return ;
    }
    if (base > 8)
        base = 8;
    std::cout << "Input index that you want to search(1 ~ " << cnt << ") : ";
    std::cin >> inputIdx;
    if ((inputIdx > 0) && (inputIdx <= cnt))
    {
        std::cout << std::endl;
        std::cout << "Searching phonebook.." << std::endl;
        std::cout << std::endl;
        std::cout << "first name : " << contact().firstName[inputIdx] << std::endl;
        std::cout << "last name : " << contact().lastName[inputIdx] << std::endl;
        std::cout << "nickname : " << contact().nickname[inputIdx] << std::endl;
        std::cout << "phone number : " << contact().phoneNumber[inputIdx] << std::endl;
        std::cout << "darkest secret : " << contact().darkestSecret[inputIdx] << std::endl;
    }
    else
        std::cout << "This index is invalid" << std::endl;
    std::cin.ignore();
}

void Phonebook::PrintInfo(int base) {
    int idx = 0;

    contact().PrintLine(11, '-');
    contact().PrintOpt();
    contact().PrintLine(11, '-');
    while ((++idx) <= cnt)
    {
        std::cout << "|" << std::setfill(' ') << std::setw(10) << idx;
        contact().SetPrintValue(contact().firstName[idx]);
        contact().SetPrintValue(contact().lastName[idx]);
        contact().SetPrintValue(contact().nickname[idx]);
        std::cout << "|" << std::endl;
    }
    contact().PrintLine(11, '-');
    Phonebook().SearchInfo(base);
}
