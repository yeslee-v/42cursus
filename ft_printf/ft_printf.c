/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/15 17:21:58 by yeslee           ###   ########.fr       */
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
		lst->zero = 0;
		lst->width = 0;
		lst->prec = 0;
		//lst->len_mod = 0;
		lst->type = '0';
		lst->len = 0;
		lst->result = 0;
		lst->cnt = 0;
	}
}

void	ft_handle_conversion(const char *str, t_lst *lst, va_list ap)
{
	if (*str == 'c')
	{
		// ft_print_c(lst);
		printf("c");
	}
	else if (*str == 's')
	{
		// ft_print_s(lst);
		printf("c");
	}
	else if (*str == 'p')
	{
		// ft_print_p(lst);
		printf("c");
	}
	else if (*str == 'd' || *str == 'i')
	{
		lst->result = va_arg(ap, int);
		ft_print_d_i(lst);
	}
	else if (*str == 'u')
	{
		// ft_print_u(lst);
		printf("c");
	}
	else if (*str == 'x')
	{
		// ft_print_x(lst);
		printf("c");
	}
	else if (*str == 'X')
	{
		// ft_print_X(lst);
		printf("c");
	}
	else if (*str == '%')
	{
		// ft_print_percent(lst);
		printf("c");
	}
	else
		return ;
}

void	ft_handle_str(const char *str, t_lst *lst, va_list ap)
{
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
//			cnt++;
		}
		else
		{
			str++;
			ft_parsing(&str, lst, ap);
			ft_handle_conversion(str, lst, ap);
//			cnt += lst->cnt;
		}
		str++;
		ft_reset(lst);
	}
//	if (*str == '\n')
//		cnt++;
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	t_lst	lst;

	ft_reset(&lst);
	va_start(ap, str);
	ft_handle_str(str, &lst, ap);
	va_end(ap);
	return (lst.cnt);
}
