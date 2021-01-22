/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/23 00:56:54 by yeslee           ###   ########.fr       */
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
		lst->dot = 0;
		lst->prec = 0;
		lst->type = '\0';
		lst->res = 0;
		lst->res_pct = '\0';
		lst->res_s = "";
		lst->sign = 0;
		lst->len = 0;
		lst->cnt = 0;
	}
}

void	ft_handle_conversion(t_lst *lst)
{
	if (lst->type == 'c' || lst->type == '%')
		ft_print_char(lst);
	else if (lst->type == 's')
		ft_print_str(lst);
	else if (lst->type == 'p')
		ft_print_p(lst);
	else if (lst->type == 'd' || lst->type == 'i' || lst->type == 'u' ||
				lst->type == 'x' || lst->type == 'X')
		ft_print_num(lst);
	return ;
}

int		ft_handle_str(const char *str, t_lst *lst, va_list *ap)
{
	int	cnt;

	cnt = 0;
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
			ft_reset(lst);
			ft_parsing(&str, lst, ap);
			ft_handle_conversion(lst);
		}
		str++;
		cnt += lst->cnt;
	}
	return (cnt);
}

int		ft_printf(const char *str, ...)
{
	int		cnt;
	va_list	ap;
	t_lst	lst;

	va_start(ap, str);
	cnt = ft_handle_str(str, &lst, &ap);
	va_end(ap);
	return (cnt);
}
