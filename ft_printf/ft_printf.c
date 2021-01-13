/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/13 17:11:31 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset(t_list *lst)
{
	if (!lst)
		return ;
	else
	{
		lst->left = 0;
		lst->zero = 0;
		lst->width = 0;
		lst->prec = 0;
		lst->len_mod = 0;
		lst->type = '0';
		lst->len = 0;
		lst->result = 0;
		lst->cnt = 0;
	}
}

int		ft_intlen(int n)
{
	int	cnt;

	cnt = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void	ft_check_conversion(const char *str, t_list *lst)
{
	// printf("type:%c\n", lst->type);
	if (*str == 'c')
		// ft_print_c(lst);
		printf("c");
	else if (*str == 's')
		// ft_print_s(lst);
		printf("c");
	else if (*str == 'p')
		// ft_print_p(lst);
		printf("c");
	else if (*str == 'd')
		ft_print_d(lst);
	else if (*str == 'i')
		// ft_print_i(lst);
		printf("c");
	else if (*str == 'u')
		// ft_print_u(lst);
		printf("c");
	else if (*str == 'x')
		// ft_print_x(lst);
		printf("c");
	else if (*str == 'X')
		// ft_print_X(lst);
		printf("c");
	else if (*str == '%')
		// ft_print_percent(lst);
		printf("c");
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	t_list	lst;

	ft_reset(&lst);
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			write(1, &(*str), 1);
		}
		else
		{
			str++;
			str = ft_parsing(str, &lst, ap);
			lst.result = va_arg(ap, int);
			lst.len = ft_intlen(lst.result);
			ft_check_conversion(str, &lst);
		}
		str++;
		ft_reset(&lst);
	}
	va_end(ap);
	return (lst.cnt);
}
