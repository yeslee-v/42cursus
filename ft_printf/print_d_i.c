/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:12:01 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/18 23:36:11 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

/*void	ft_flag_off(t_lst *lst)
{
	printf("no flag\n\n"i);
}*/

void	ft_flag_on(t_lst *lst)
{
	if (lst->left)
	{
		lst->sign ? ft_putchar((lst->res * -1)) : ft_putchar(lst->res);
		if (lst->left_size > 0)
			while (lst->left_size--)
				ft_putchar(' ');
	}
	else if (lst->zero)
	{
		lst->sign ? ft_putchar('-') : 0;
		if (lst->zero_size > 0)
			while (lst->zero_size--)
				ft_putchar('0');
		ft_putchar(lst->res);
	}
}

void	ft_print_detail(t_lst *lst)
{
	if ((lst->width <= lst->len) && (lst->prec <= lst->len))
		ft_putstr(ft_itoa(lst->res));
	else if (lst->left || lst->zero)
		ft_flag_on(lst);
	//else
	//	ft_flag_off(lst);
}

void	ft_print_d_i(t_lst *lst)
{
	lst->zero_size = lst->len < lst->prec ? lst->prec - lst->len : 0;
	((lst->prec < lst->width) && (lst->len < lst->width)) ? 
		lst->left_size = (lst->len < lst->prec ? 
			lst->width - lst->prec : lst->width - lst->prec) : 0;
	ft_print_detail(lst);
}
