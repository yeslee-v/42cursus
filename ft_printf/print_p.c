/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:58:17 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/23 12:22:10 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_neg_to_pos(t_lst *lst)
{
	if (lst->sign)
	{
		ft_putchar('-');
		lst->res *= -1;
	}
}

static void	ft_res_print(t_lst *lst)
{
	if (lst->dot && !(lst->prec) && !(lst->res))
		return ;
	else
	{
		ft_putstr("0x");
		ft_putstr(ft_itoa_base((lst->res), 16, lst->type));
	}
}

static void	ft_flag_off(t_lst *lst)
{
	if ((lst->width < lst->len) && (lst->len < lst->prec))
		lst->zero_size = lst->prec - lst->len;
	else if ((lst->len < lst->width) && (lst->len < lst->prec))
		if (lst->prec < lst->width)
			lst->zero_size = lst->prec - lst->len;
	lst->cnt += lst->left_size + lst->zero_size + lst->sign + lst->len;
	ft_flag_print(lst->left_size, ' ');
	ft_neg_to_pos(lst);
	ft_flag_print(lst->zero_size, '0');
	ft_res_print(lst);
}

static void	ft_flag_on(t_lst *lst)
{
	lst->cnt += lst->left_size + lst->zero_size + lst->sign + lst->len;
	if (lst->left)
	{
		ft_neg_to_pos(lst);
		ft_flag_print(lst->zero_size, '0');
		ft_res_print(lst);
		ft_flag_print(lst->left_size, ' ');
	}
	else if (lst->zero)
	{
		if (!(lst->zero_size) && !(lst->dot))
			lst->zero_size = lst->width - lst->len;
		else if (lst->dot)
			ft_flag_print(lst->left_size, ' ');
		ft_neg_to_pos(lst);
		ft_flag_print(lst->zero_size, '0');
		ft_res_print(lst);
	}
}

void	ft_print_p(t_lst *lst)
{
	if (lst->dot && !(lst->prec) && !(lst->res))
		lst->len = 0;
	else if ((lst->width <= lst->len) && (lst->prec <= lst->len))
	{
		ft_res_print(lst);
		lst->cnt += lst->len;
		return ;
	}
	lst->zero_size = lst->len < lst->prec ? lst->prec - lst->len : 0;
	if ((lst->prec < lst->width) && (lst->len < lst->width))
		lst->left_size = (lst->len < lst->prec) ? lst->width - lst->prec
												: lst->width - lst->len;
	(lst->left || lst->zero) ? ft_flag_on(lst) : ft_flag_off(lst);
}
