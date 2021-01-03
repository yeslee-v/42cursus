/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/03 22:59:09 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(char *c)
{
	write(1, &(*c), 1);
}

void	ft_reset(t_list *lst)
{
	// lst->space = 0;
	// lst->plus = 0;
	lst->left = 0;
	lst->zero = 0;
	// lst->sharp = 0;
	lst->width = 0;
	lst->prec = 0;
	lst->type = 0;
	lst->len = 0;
	lst->result = 0;
	lst->cnt = 0;
}

int		ft_printf(const char *str, ...)
{
	t_list	*lst;
	va_list	ap;

	ft_reset(lst);
	va_start(ap, str);
	lst->result = va_arg(ap, int);
	lst->len = ft_len(lst->result);
	while (*str)
	{
		if (*str != '%')
			ft_putchar((char *)str);
		else
		{
			str++;
			str = ft_parsing(str);
			ft_flag_d(lst);
		}
		str++; // error(sagmentation fault)
		ft_reset(lst);
	}
	va_end(ap);
	return (lst->len);
}
