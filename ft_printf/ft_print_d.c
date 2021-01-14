/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:35:56 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/14 23:38:44 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_negative(t_lst *lst)
{
	if (lst->result < 0)
	{
		write(1, "-", 1);
		lst->result *= -1;
		lst->len--;
	}
	return ;
}
/*
void	ft_width_len(t_lst *lst)
{
	if (lst->left)
	{
		
	}
	else if (lst->zero)
	{

	}
	else
	{

	}
}*/

void	ft_print_d(t_lst *lst)
{
	if (lst->prec <= lst->len && lst->width <= lst->len)
		lst->cnt += lst->len;
	else
	{
		if (lst->width <= lst->prec)
			lst->cnt += ft_size(lst->prec);
		else
			lst->cnt += ft_size(lst->width);
	}
	if (lst->result < 0)
		lst->len++;
	//ft_width_len(lst);
}
