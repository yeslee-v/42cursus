/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:59:04 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/26 19:42:45 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_res_print_c(t_lst *lst)
{
	if (lst->type == 'c')
		ft_putchar(lst->res);
	else if (lst->type == '%')
		ft_putchar(lst->res_pct);
}

void	ft_cflag_off(t_lst *lst)
{
	lst->cnt += lst->left_size + lst->zero_size + lst->len;
	ft_flag_print(lst->left_size, ' ');
	ft_res_print_c(lst);
}

void	ft_cflag_on(t_lst *lst)
{
	if (lst->left)
	{
		lst->cnt += lst->left_size + lst->zero_size + lst->len;
		ft_res_print_c(lst);
		ft_flag_print(lst->left_size, ' ');
	}
	else if (lst->zero)
	{
		lst->zero_size = lst->width - lst->len;
		lst->cnt += lst->left_size + lst->zero_size + lst->len;
		ft_flag_print(lst->zero_size, '0');
		ft_res_print_c(lst);
	}
}

void	ft_print_char(t_lst *lst)
{
	if (lst->width <= lst->len)
	{
		ft_res_print_c(lst);
		lst->cnt += lst->len;
		return ;
	}
	lst->left_size = lst->len < lst->width ? lst->width - lst->len : 0;
	(lst->left || lst->zero) ? ft_cflag_on(lst) : ft_cflag_off(lst);
}
