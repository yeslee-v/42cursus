/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/19 19:47:17 by yeslee           ###   ########.fr       */
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
		//	lst.cnt++;
		}
		else
		{
			str++;
			while (ft_istype(*str) == '0')
			{
				if (*str == '-')
					lst.left = '-';
				else if (*str == '0')
					lst.zero = '0';
				else if (ft_atoi((char *)str))
					lst.width = ft_atoi((char *)str);
				else if (*str == '.')
				{
					str++;
					if (ft_atoi((char *)str))
						lst.prec = ft_atoi((char *)str);
				}
				str++;
			}
			if (ft_istype(*str))
				lst.type = *str;
		}
		str++;
	}
	lst.result = va_arg(ap, int);
	va_end(ap);
	/*printf("space: %c\n", lst.left);
	printf("space: %c\n", lst.zero);
	printf("width: %d\n", lst.width);
	printf("prec: %d\n", lst.prec);
	printf("type: %c\n", lst.type);
	*/
	return (lst.result);
}
