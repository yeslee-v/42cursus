/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:11:57 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/15 15:28:31 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>
int	ft_printf(const char *str, ...)
{
	int		result;
	t_list	lst;
	va_list	ap;

	va_start(ap, str);
	result = va_arg(ap, int);
	lst.print = ft_itoa(result);
	lst.len = ft_strlen(lst.print);
	while (*str)
	{
		if (*str != '%')
		{
			if (*str == '.') // precision
			{
				lst.precision = ft_atoi((char *)(str + 1));
				while (lst.precision > lst.len)
				{
					write(1, "0", 1);
					lst.precision--;
					//printf("lst: %d %d\n", lst.precision, lst.len);
				}
				write(1, lst.print, lst.len);
			}
			write(1, &(*str), 1);  // /n
			lst.cnt++;
		}
		if (*(str + 1) == 'd')
		{
			write(1, lst.print, lst.len);
			str++;
			lst.cnt++;
		}
		str++;
	}
	lst.cnt++;
	va_end(ap);
	return (lst.cnt);
}
