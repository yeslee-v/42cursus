/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:38:00 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/15 17:24:27 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_istype(const char *str)
{
	if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd' ||
		*str == 'i' || *str == 'u' || *str == 'x' || *str == 'X' ||
		*str == '%')
	{
		return (1);
	}
	return (0);
}

/*
int			ft_input_w_p(const char **str, int num, va_list ap)
{
	num = ft_if_star(*str, num, ap);
	if (**str != '*')
		*str += ft_size(num);
	else
		(*str)++;
	return (num);
}*/

void	ft_parsing(const char **str, t_lst *lst, va_list ap)
{
	ft_check_flag(str, lst);
	ft_check_width(str, lst, ap);
	ft_check_prec(str, lst, ap);
//	if (ft_type(str))
//		str++;
}
