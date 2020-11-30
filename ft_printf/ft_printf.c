/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/30 15:41:14 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	t_list	lst;
	va_list	ap;

	va_start(ap, str);
	ft_reset(&lst);
	while (*str)
	{
		if (*str != '%')
			ft_putchar((char *)str);
		else
		{
			str++;
			if (ft_type(*str) == '0')
			{
				if (*str == '-')
					lst.left = 1;
				else if (*str == '0')
					lst.zero = 1;
				while (*str == '-' || *str == '0')
    				str++;
				while (ft_atoi((char *)str))
				{
					lst.width = (lst.width * 10) + (*str - '0');
					str++;
				}
				if (*str == '.')
				{
					str++;
					while (ft_atoi((char *)str))
					{
						lst. prec = (lst.prec * 10) + (*str - '0');
						str++;
					}
				}
			}
			if (ft_type(*str))
				lst.type = *str;
			str++;
		}
		str++;
	}
	lst.result = va_arg(ap, int);
	lst.len = ft_len(lst.result);
	write(1, ft_itoa(lst.result), lst.len);
	ft_reset(&lst);
	va_end(ap);

	return (lst.len);
}
