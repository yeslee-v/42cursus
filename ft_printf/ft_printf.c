/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/16 18:06:23 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_list	lst;
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str);
		else if (*str == '%')
		{
			if (*str == ' ' ? lst.space = ' ' : lst.space = 0)
			if (*str == '+' ? lst.space = '+' : lst.space = 0)
			if (*str == '-' ? lst.space = '-' : lst.space = 0)
			if (*str == ' ' ? lst.space = 1 : lst.space = 0)
			if (*str == ' ' ? lst.space = 1 : lst.space = 0)
		}
		str++;
	}
}
