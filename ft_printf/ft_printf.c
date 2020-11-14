/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:11:57 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/14 21:18:37 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_printf(const char *str, ...)
{
	int		cnt;
	int		result;
	t_list	lst;
	va_list	ap;

	cnt = 1;
	va_start(ap, str);
	result = va_arg(ap, int);
	lst.precision = ft_atoi((char *)str + 1);
	lst.len = ft_strlen(ft_itoa(result));
	while (*str)
	{
		if (*str != '%')
		{
			if (*str == '.')
			{
				if (lst.precision > lst.len)
				{
					write(1, "0", 1);
					lst.precision--;
					// printf("%.5d", 123) >> 00123
				}
				else // <=
				{
					write(1, ft_itoa(result), lst.len);
					// 123 그대로 출력
				}
			}
			write(1, &(*str), 1);
			cnt++;
		}
		else
		{
			if (*(str + 1) == 'd')
			{
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
