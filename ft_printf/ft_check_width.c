/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:07:28 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/16 21:53:58 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_width(const char **str, t_lst *lst, va_list *ap)
{
	if (**str == '*' || ft_atoi((char *)str))
	{
		if (**str == '*')
			lst->width = va_arg(*ap, int);
		else
		{
			while (**str != '.' && !(ft_istype(*str)))
			{
				lst->width = (lst->width * 10) + (**str - '0');
				(*str)++;
			}
		}
		if (lst->width < 0)
		{
			lst->left = 1;
			lst->zero = 0;
			lst->width *= -1;
		}
	}
	return ;
}
