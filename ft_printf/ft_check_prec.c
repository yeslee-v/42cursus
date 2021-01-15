/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:16:08 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/15 16:41:12 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_prec(const char **str, t_lst *lst, va_list ap)
{
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
			lst->prec = va_arg(ap, int);
		else if (ft_atoi((char *)str))
		{
			while (**str != '.' && !(ft_istype(*str)))
			{
				lst->prec = (lst->prec * 10) + (**str - '0');
				(*str)++;
			}
		}
	}
	return ;
}
