/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:37:59 by yeslee            #+#    #+#             */
/*   Updated: 2021/12/20 11:38:04 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void) {
    int         idx = 0;
    std::string cmd;
    Phonebook   phonebook;

    while (1)
    {
        std::cout << std::endl;
        std::cout << "Choose Option(ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);
        if ((cmd == "ADD") && (cmd.length() == 3))
        {
            if (idx > 7)
                idx = idx % 8;
            phonebook.AddInfo(idx);
            std::cout << std::endl;
            idx++;
        }
        else if ((cmd == "SEARCH") && (cmd.length() == 6))
            phonebook.PrintInfo(idx);
        else if ((cmd == "EXIT") && (cmd.length() == 4))
        {
            std::cout << "program exited" << std::endl;
            return (0);
        }
        else
            std::cout << "command not found: " << cmd << std::endl;
        std::cin.clear();
    }
    return (0);
}
