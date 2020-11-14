/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:35:27 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/14 14:50:32 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_normal_d(const char *str, ...)
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
