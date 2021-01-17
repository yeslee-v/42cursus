/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:44:23 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/17 21:47:46 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(const char **str, t_lst *lst)
{
	while (**str == '-' || **str == '0')
	{
		if (**str == '-')
			lst->left = 1;
		else if (**str == '0')
			if (!(lst->left))
				lst->zero = 1;
		(*str)++;
	}
}
