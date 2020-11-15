/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:03:16 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/15 14:42:21 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>
int	ft_precision_d(const char *str, ...)
{
	int		cnt;
	int		result;
	t_list	lst;
	va_list	ap;

	cnt = 1;
	va_start(ap, str);
	result = va_arg(ap, int);
	lst.print = ft_itoa(result);
	lst.len = ft_strlen(lst.print);
	while (*str)
	{
		if (*str != '%')
		{
			if (*str == '.')
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
			//write(1, &(*str), 1);
			cnt++;
		}
		else
		{
			if (*(str + 1) == 'd')
			{
				write(1, lst.print, lst.len);
				str++;
				cnt++;
			}
		}
		str++;
	}
	cnt++;
	va_end(ap);
	return (cnt);
}
