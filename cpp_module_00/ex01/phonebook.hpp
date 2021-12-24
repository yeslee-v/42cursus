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

#include "contact.hpp"
#include <iostream>
#include <iomanip>

class Phonebook {
private:
    int         cnt;
    Contact contact();

public:
    void AddInfo(int idx);
    void PrintInfo(int idx);
    void SearchInfo(int base);

    Phonebook() {
        cnt = 0;
    }
};

#endif
