/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:11:57 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/14 14:50:30 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int		cnt;
	int		result;
	va_list	ap;

	cnt = 1;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			write(1, &(*str), 1);
			cnt++;
		}
		else
		{
			if (*(str + 1) == 'd')
			{
				result = va_arg(ap, int);
				write(1, ft_itoa(result), ft_strlen(ft_itoa(result)));
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
