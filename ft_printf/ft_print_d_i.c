/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:00:20 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/16 21:50:58 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_res_negative(t_lst *lst)
{
	if (lst->res < 0)
	{
		lst->len = ft_size(lst->res) + 1;
		lst->sign = 1;
		lst->res *= -1;
	}
	else
		lst->len = ft_size(lst->res);

}

void	ft_printf_d_i(t_lst *lst)
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
	ft_printf_d_i(lst);
}
