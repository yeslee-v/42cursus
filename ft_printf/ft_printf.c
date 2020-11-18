/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/18 20:40:28 by yeslee           ###   ########.fr       */
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
		printf("circle: %c\n", *str);
		if (*str != '%')
			ft_putchar((char *)str);
		else
		{
			while (!ft_istype(*str))
			{
				if (*str == '%')
				{
					str++;
					if (*str == '-')
						lst.space = '-';
					else if (*str == '0')
						lst.space = '0';
				}
				else if (*str == '.')
				{
					str++;
				//printf("str: %c\n", *str);
				//printf("digit: %d\n", ft_atoi((char *)str));
					if (ft_atoi((char *)str))
						lst.prec = ft_atoi((char *)str);
				}
				str++;
			}
				lst.type = *str;
			str++;
		}
		str++;
	}
	printf("space: %c\n", lst.space);
	printf("prec: %d\n", lst.prec);
	printf("type: %c\n\n", lst.type);
	return (0);
}
