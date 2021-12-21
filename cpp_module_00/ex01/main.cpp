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

void PrintOpt(void) {
    // std::cout << idx, firstName, lastName, nickname
    std::cout << std::setfill(' ');
    std::cout << "|" << std::setw(10) << "index";
    std::cout << "|" << std::setw(10) << "first name";
    std::cout << "|" << std::setw(10) << "last name";
    std::cout << "|" << std::setw(10) << "nickname";
    std::cout << std::endl;
}

void PrintLine(void) {
    std::cout << "|" << std::setfill('-') << std::setw(10);
    std::cout << "|" << std::setw(10);
    std::cout << "|" << std::setw(10);
    std::cout << "|" << std::setw(10);
    std::cout << "|" << std::setw(10);
    std::cout << "|" << std::endl;
}

int main()
{
    int         idx;
    int         cnt;
    Phonebook   info;
    std::string cmd;

    idx = 0;
    cnt = 0;
    while (1)
    {
        std::cout << "Choose Option(ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);

        if ((cmd == "ADD") && (cmd.length() == 3))
        {
            idx = cnt % 8;
            info.AddInfo(idx);
            std::cout << std::endl;
            idx++;
        }
        else if ((cmd == "SEARCH") && (cmd.length() == 6))
        {
            // 각 열 : 너비 10 문자, 가로 정렬, ‘|’ 문자로 구분 → 열 너비보다 긴 출력 문자열은 잘리고 마지막 표시 가능 문자는 점(.)으로 치환
            PrintLine();
            PrintOpt();
            info.PrintInfo(idx);

            // 원하는 연락처 항목의 인덱스 입력 → 한 필드당 한 줄씩 출력
            // 의미없는 입력값에 대해 적절한 동작 정의 + 그 외의 입력값은 버려짐
//            std::cout << "here is SEARCH" << std::endl;
        }
        else if ((cmd == "EXIT") && (cmd.length() == 4))
        {
            std::cout << "program exited" << std::endl;
            return (0);
        }
        else
            std::cout << "command not found: " << cmd << std::endl;
    }
    return (0);
}
