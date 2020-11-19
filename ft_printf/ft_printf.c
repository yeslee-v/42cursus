/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/19 17:33:41 by yeslee           ###   ########.fr       */
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
	//	printf("str: %c\n", *str);
		if (*str != '%')
			ft_putchar((char *)str);
		else
		{
			while (*str)
			{
	//			printf("in: %s\n", str);
				str++;
				if (*str == '-')
					lst.space = '-';
				else if (*str == 0)
					lst.space = 0;
				else if (ft_atoi((char *)str))
					lst.width = ft_atoi((char *)str);
				else if (*str == '.')
				{
					str++;
					if (ft_atoi((char *)str))
						lst.prec = ft_atoi((char *)str);
				}
				printf("istype: %c\n", *str);
				/*else if (ft_istype(*str))
					lst.type = *str;
				*/
				str++;
			}
		}
		str++;
	}
	/*printf("space: %c\n", lst.space);
	printf("width: %d\n", lst.width);
	printf("prec: %d\n", lst.prec);
	printf("type: %c\n\n", lst.type);
	*/
	return (0);
}
