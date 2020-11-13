/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:11:57 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/13 16:31:28 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int		num;
	int		result;
	char	s;
	va_list	ap;

	va_start(ap, str);
	//printf("%s", str);	// %d
	while (*str)
	{
		if (*str != '%')
			printf("%c", *str);
			//write(1, *str, 1);
		else // *str == %
		{
				printf("*");
			if (*(str + 1) == 'd')
			{
				result = va_arg(ap, int);
				printf("result: %d\n", result);
			}
		}
		str++;
	}
	va_end(ap);
	return (result);
}
