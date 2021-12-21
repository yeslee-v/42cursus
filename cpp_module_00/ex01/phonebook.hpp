/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:18:22 by yeslee            #+#    #+#             */
/*   Updated: 2021/12/15 21:18:05 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>

class Phonebook {
private:
    std::string	firstName[8];
    std::string	lastName[8];
    std::string	nickname[8];
    std::string	phoneNumber[8];
    std::string	darkestSecret[8];

public:
    void AddInfo(int idx);
    void PrintInfo(int idx);

};

#endif
