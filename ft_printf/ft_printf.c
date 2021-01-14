/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/14 11:58:39 by yeslee           ###   ########.fr       */
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
		lst->len_mod = 0;
		lst->type = '0';
		lst->len = 0;
		lst->result = 0;
		lst->cnt = 0;
	}
}

void	ft_check_conversion(const char *str, t_lst *lst)
{
	if (*str == 'c')
		// ft_print_c(lst);
		printf("c");
	else if (*str == 's')
		// ft_print_s(lst);
		printf("c");
	else if (*str == 'p')
		// ft_print_p(lst);
		printf("c");
	else if (*str == 'd' || *str == 'i')
		ft_print_d(lst);
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

int		ft_res_cnt(t_lst *lst)
{
	if (lst->prec < lst->width && lst->len < lst->width)
		lst->cnt += ft_size(lst->width);
	else
	{
		if (lst->prec < lst->len)
			lst->cnt += ft_size(lst->prec);
		else
			lst->cnt += ft_size(lst->len);
	}
	return (lst->cnt);
}

int		ft_printf(const char *str, ...)
{
	int		cnt;
	va_list	ap;
	t_lst	lst;

	cnt = 0;
	ft_reset(&lst);
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
			str++;
			cnt++;
			str = ft_parsing(str, &lst, ap);
			lst.result = va_arg(ap, int);
			lst.len = ft_size(lst.result);
			ft_check_conversion(str, &lst);
			cnt += ft_res_cnt(&lst);
		}
		str++;
		ft_reset(&lst);
	}
	va_end(ap);
	return (cnt);
}
