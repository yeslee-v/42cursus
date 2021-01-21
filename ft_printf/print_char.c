/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:59:04 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/22 00:09:41 by yeslee           ###   ########.fr       */
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
	if (lst->type == 'c')
		(!(lst->res)) ? ft_putchar('\0') : ft_putchar(lst->res);
	else if (lst->type == '%')
		ft_putchar(lst->res_pct);
}

static void	ft_flag_off(t_lst *lst)
{
	lst->cnt += lst->left_size + lst->zero_size + lst->sign + lst->len;
	ft_flag_print(lst->left_size, ' ');
	ft_neg_to_pos(lst);
	ft_res_print(lst);
}

static void	ft_flag_on(t_lst *lst)
{
	lst->cnt += lst->left_size + lst->zero_size + lst->sign + lst->len;
	if (lst->left)
	{
		ft_neg_to_pos(lst);
		ft_res_print(lst);
		ft_flag_print(lst->left_size, ' ');
	}
	else if (lst->zero && (lst->type == '%'))
	{
		if (!(lst->zero_size))
			lst->zero_size = lst->width - lst->len;
		ft_neg_to_pos(lst);
		ft_flag_print(lst->zero_size, '0');
		ft_res_print(lst);
	}
}

void		ft_print_char(t_lst *lst)
{
	if (lst->width <= lst->len)
	{
		ft_res_print(lst);
		lst->cnt += lst->len;
		return ;
	}
	lst->left_size = lst->len < lst->width ? lst->width - lst->len : 0;
	if (lst->type == 'c')
		lst->left ? ft_flag_on(lst) : ft_flag_off(lst);
	else if (lst->type == '%')
		(lst->left || lst->zero) ? ft_flag_on(lst) : ft_flag_off(lst);
}
