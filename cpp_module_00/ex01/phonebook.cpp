/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:18:36 by yeslee            #+#    #+#             */
/*   Updated: 2022/01/03 11:24:16 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <cstdlib>

Phonebook::Phonebook() {
    cnt = 0;
}

Phonebook::~Phonebook() {}

void Phonebook::PrintValue(char c, std::string str) {
    std::cout << "|" << std::setfill(c) << std::setw(10) << str;
}

void Phonebook::SetPrintValue(std::string str) {
	std:: string value;

    if (str.length() > 10)
	{
		value = str.substr(0, 9);
        value.append(".");
	}
	else
		value = str.substr(0, 10);
	PrintValue(' ', value);
}

void Phonebook::PrintOpt(void) {
    PrintValue(' ', "index");
    PrintValue(' ', "first name");
    PrintValue(' ', "last name");
    PrintValue(' ', "nickname");
    std::cout << "|" << std::endl;
}

void Phonebook::PrintLine(int n, char c) {
    int i = 4;

    std::cout << "|" << std::setfill(c) << std::setw(n);
    while (--i)
        std::cout << "|" << std::setw(n);
    std::cout << "|" << std::endl;
}

void Phonebook::AddInfo(int idx) {
    std::string info[5];

    std::cout << "first name : ";
    std::getline(std::cin, info[FIRSTNAME]);
    std::cout << "last name : ";
    std::getline(std::cin, info[LASTNAME]);
    std::cout << "nickname : ";
    std::getline(std::cin, info[NICKNAME]);
    std::cout << "phone number : ";
    std::getline(std::cin, info[PHONENUMBER]);
    std::cout << "darkest secret : ";
    std::getline(std::cin, info[DARKESTSECRET]);
    if (cnt < 8)
        cnt++;
    contact[idx].SetValue(info);
}

void Phonebook::SearchInfo(int base) {
	int			inputIdx;
	std::string tmp;;

    if (cnt == 0)
    {
        std::cout << "Phonebook is empty" << std::endl;
        return ;
    }
    if (base > 8)
        base = 8;
    std::cout << "Input index that you want to search(1 ~ " << cnt << ") : ";
	std::getline(std::cin, tmp);
	inputIdx = atoi(tmp.c_str());
    if (((--inputIdx) > -1) && (inputIdx < cnt))
    {
        std::cout << std::endl;
        std::cout << "Searching phonebook.." << std::endl;
        std::cout << std::endl;
        std::cout << "first name : " << contact[inputIdx].GetValue(FIRSTNAME) << std::endl;
        std::cout << "last name : " << contact[inputIdx].GetValue(LASTNAME) << std::endl;
        std::cout << "nickname : " << contact[inputIdx].GetValue(NICKNAME) << std::endl;
        std::cout << "phone number : " << contact[inputIdx].GetValue(PHONENUMBER) << std::endl;
        std::cout << "darkest secret : " << contact[inputIdx].GetValue(DARKESTSECRET) << std::endl;
    }
    else
        std::cout << "This index is invalid" << std::endl;
}

void Phonebook::PrintInfo(int base) {
    int idx = -1;

    PrintLine(11, '-');
    PrintOpt();
    PrintLine(11, '-');
    while (((++idx + 1) <= cnt))
    {
        std::cout << "|" << std::setfill(' ') << std::setw(10) << (idx + 1);
        SetPrintValue(contact[idx].GetValue(FIRSTNAME));
        SetPrintValue(contact[idx].GetValue(LASTNAME));
        SetPrintValue(contact[idx].GetValue(NICKNAME));
        std::cout << "|" << std::endl;
    }
    PrintLine(11, '-');
    SearchInfo(base);
}
