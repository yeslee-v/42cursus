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
    std::getline(std::cin, firstName[idx]);
    std::getline(std::cin, lastName[idx]);
    std::getline(std::cin, nickname[idx]);
    std::getline(std::cin, phoneNumber[idx]);
    std::getline(std::cin, darkestSecret[idx]);
}

void Phonebook::PrintInfo(int idx) {
    int tmp;

    tmp = idx + 1;
    while (--tmp)
    {
        std::cout << idx << std::endl;
        std::cout << firstName[idx] << std::endl;
        std::cout << lastName[idx] << std::endl;
        std::cout << nickname[idx] << std::endl;
    }
}