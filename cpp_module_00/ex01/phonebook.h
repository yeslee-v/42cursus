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


class phonebook {
    std::string	first_name[8];
    std::string	last_name[8];
    std::string	nickname[8];
    std::string	phone_number[8];
    std::string	darkest_secret[8];

};

#endif
