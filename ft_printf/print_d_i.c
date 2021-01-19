/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:12:01 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/20 00:30:56 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_neg_to_pos(t_lst *lst)
{
	if (lst->sign)
	{
		ft_putchar('-');
		lst->res *= -1;
		lst->sign = 0;
	}
}

void	ft_flag_print(int size, char c)
{
	if (size > 0)
		while (size--)
			ft_putchar(c);
}

void	ft_flag_off(t_lst *lst)
{
	if ((lst->prec < lst->len) && (lst->len < lst->width))
		lst->left_size = lst->width - lst->len;
	else if ((lst->width < lst->len) && (lst->len < lst->prec))
		lst->zero_size = lst->prec - lst->len;
	else if ((lst->len < lst->width) && (lst->len < lst->prec))
	{
		if (lst->prec < lst->width)
		{
			lst->left_size = lst->width - lst->prec;
			lst->zero_size = lst->prec - lst->len;
		}
	}
	ft_flag_print(lst->left_size, ' ');
	ft_neg_to_pos(lst);
	ft_flag_print(lst->zero_size, '0');
	ft_putstr(ft_itoa(lst->res));
}

void	ft_flag_on(t_lst *lst)
{
	ft_neg_to_pos(lst);
	if (lst->left)
	{
		ft_flag_print(lst->zero_size, '0');
		ft_putstr(ft_itoa(lst->res));
		ft_flag_print(lst->left_size, ' ');
	}
	else if (lst->zero)
	{
		if (!(lst->zero_size))
			lst->zero_size = lst->width - lst->len;
		ft_flag_print(lst->zero_size, '0');
		ft_putstr(ft_itoa(lst->res));
	}
}

void	ft_print_d_i(t_lst *lst)
{
	if ((lst->width <= lst->len) && (lst->prec <= lst->len))
	{
		ft_putstr(ft_itoa(lst->res));
		return ;
	}
	lst->zero_size = lst->len < lst->prec ? lst->prec - lst->len : 0;
	if ((lst->prec < lst->width) && (lst->len < lst->width))
		lst->left_size = (lst->len < lst->prec) ?
			lst->width - lst->prec : lst->width - lst->len;
	(lst->left || lst->zero) ? ft_flag_on(lst) : ft_flag_off(lst);
}
