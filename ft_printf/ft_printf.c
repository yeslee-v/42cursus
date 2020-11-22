/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/22 18:02:58 by yeslee           ###   ########.fr       */
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
		{
			ft_putchar((char *)str);
//			lst.cnt++;
		}
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
		/*	printf("left: %d\n", lst.left);
			printf("zero: %d\n", lst.zero);
			printf("width: %d\n", lst.width);
			printf("prec: %d\n", lst.prec);
			printf("cnt: %d\n", lst.cnt);
			printf("type: %c\n", lst.type);
			printf("len: %d\n", lst.len);*/
		}
		str++;
		printf("str: %c\n", *str);
	}
	lst.result = va_arg(ap, int);
	lst.len = ft_len(lst.result);
	ft_reset(&lst);
	va_end(ap);

	return (lst.result);
}
