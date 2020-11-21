/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/21 12:29:19 by yeslee           ###   ########.fr       */
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
		{
			ft_putchar((char *)str);
			lst.cnt++;
		}
		else
		{
			str++;
			while (ft_type(*str) == '0')
			{
				if (*str == '-')
					lst.left = '-';
				else if (*str == '0')
					lst.zero = '0';
				while (*str != '-' || *str != '0')
    				str++;
				if (ft_atoi((char *)str))
				{
					//printf("atoi: %d\n", ft_atoi((char *)str));
					lst.width = ft_atoi((char *)str);
					//str++;
				}
				else if (*str == '.')
				{
					str++;
					if (ft_atoi((char *)str))
						lst.prec = ft_atoi((char *)str);
				}
				str++;
			}
			if (ft_type(*str))
				lst.type = *str;
		}
		str++;
	}
	lst.result = va_arg(ap, int);
	lst.len = ft_len(lst.result);
	va_end(ap);
//	printf("left: %c\n", lst.left);
//	printf("zero: %c\n", lst.zero);
//	printf("width: %d\n", lst.width);
//	printf("prec: %d\n", lst.prec);
//	printf("cnt: %d\n", lst.cnt);
//	printf("type: %c\n", lst.type);
	
	return (lst.result);
}
