/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:11:57 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/13 19:53:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, str);
	//printf("%s", str);	// %d
	while (*str)
	{
		if (*str != '%')
			//printf("%c", *str);
			write(1, &(*str), 1);
		else // *str == %
		{
				//printf("*");
			if (*(str + 1) == 'd')
			{
				result = va_arg(ap, int);
				write(1, ft_itoa(result), ft_strlen(ft_itoa(result)));
				//printf("%d", result);
				str++;
			}
		}
		str++;
	}
	va_end(ap);
	//printf("%d\n", result);
	return (result);
}
