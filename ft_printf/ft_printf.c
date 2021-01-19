/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/19 22:42:45 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset(t_lst *lst)
{
	if (!lst)
		return ;
	else
	{
		lst->left = 0;
		lst->left_size = 0;
		lst->zero = 0;
		lst->zero_size = 0;
		lst->width = 0;
		lst->prec = 0;
		lst->type = '0';
		lst->res = 0;
		lst->sign = 0;
		lst->len = 0;
		lst->cnt = 0;
	}
}

void	ft_handle_conversion(t_lst *lst)
{
	if (lst->type == 'c')
		printf("c");
	else if (lst->type == 's')
		printf("s");
	else if (lst->type == 'p')
		printf("p");
	else if (lst->type == 'd' || lst->type == 'i')
		ft_print_d_i(lst);
	else if (lst->type == 'u')
		printf("u");
	else if (lst->type == 'x')
		printf("x");
	else if (lst->type == 'X')
		printf("X");
	else if (lst->type == '%')
		printf("percent");
	else
		return ;
}

void	ft_handle_str(const char *str, t_lst *lst, va_list *ap)
{
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			lst->cnt++;
		}
		else
		{
			str++;
			ft_parsing(&str, lst, ap);
			ft_handle_conversion(lst);
		}
		str++;
		ft_reset(lst);
	}
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	t_lst	lst;

	ft_reset(&lst);
	va_start(ap, str);
	ft_handle_str(str, &lst, &ap);
	va_end(ap);
	return (lst.cnt);
}
