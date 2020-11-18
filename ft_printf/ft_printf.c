/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/18 17:54:28 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	t_list	lst;
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar((char *)str);
		else if (*str == '%')
		{
			if (*str == '-')
				lst.space = '-';
			else if (*str == '0')
				lst.space = '0';
		}
		else if (*str == '.')
		{
			str++;
			if (ft_isdigit(ft_atoi((char *)str)))
				lst.prec = *str;
		}
		else if (*str == 'c')
			lst.type = 'c';
		else if (*str == 's')
			lst.type = 's';
		else if (*str == 'p')
			lst.type = 'p';
		else if (*str == 'd')
			lst.type = 'd';
		else if (*str == 'i')
			lst.type = 'i';
		else if (*str == 'u')
			lst.type = 'u';
		else if (*str == 'x')
			lst.type = 'x';
		else if (*str == 'X')
			lst.type = 'X';
		else if (*str == '%')
			lst.type = '%';
		printf("space: %c\n", lst.space);
		printf("prec: %d\n", lst.prec);
		printf("type: %c\n", lst.type);
//		printf("%c\n", *lst.space);
		str++;
	}
	return (0);
}
