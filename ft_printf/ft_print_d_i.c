/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:00:20 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/16 11:17:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_printf_d_i(t_lst *lst)
{
	if ((lst->width <= lst->len) && (lst->prec) <= (lst->len))
		ft_putstr(ft_itoa(lst->res));
/*	else if (lst->left)
	{
		
	}
	else if (lst->zero)
	{

	}
	else
	{

	}*/
}

void	ft_print_d_i(t_lst *lst)
{
	lst->res < 0 ? lst->res *= -1 : 1;
	lst->res < 0 ? lst->len = ft_size(lst->res) + 1 : ft_size(lst->res);
	lst->res < 0 ? lst->sign = 1 : 0;
/*	if (lst->prec <= lst->len && lst->width <= lst->len)
		lst->cnt += lst->len;
	else
	{
		if (lst->width <= lst->prec)
			lst->cnt += ft_size(lst->prec);
		else
			lst->cnt += ft_size(lst->width);
	}
	if (lst->result < 0)
		lst->len++;*/
	ft_printf_d_i(lst);
}
