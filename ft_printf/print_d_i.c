/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:12:01 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/17 22:15:21 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_detail(t_lst *lst)
{
	if ((lst->width <= lst->len) && (lst->prec) <= (lst->len))
		ft_putstr(ft_itoa(lst->res));
}

void	ft_print_d_i(t_lst *lst)
{
	int	zero;
	int	minus;

	zero = lst->prec - lst->len;
	minus = lst->prec < lst->len ? lst->len - lst->prec : lst->prec - lst->len;
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
	ft_print_detail(lst);
}
