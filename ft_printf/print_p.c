/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:15:28 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/29 02:06:33 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_res_print_p(t_lst *lst)
{
	char	*res;

	res = "0";
	ft_putstr("0x");
	if (lst->dot && !(lst->prec) && !(lst->res))
		return ;
	else
	{
		res = ft_itoa_base(lst->res, 16, lst->type);
		ft_putstr(res);
		free(res);
	}
}

void	ft_pflag_off(t_lst *lst)
{
	if ((lst->width < lst->len) && (lst->len < lst->prec))
		lst->zero_size = lst->prec - lst->len;
	else if ((lst->len < lst->width) && (lst->len < lst->prec))
		if (lst->prec < lst->width)
			lst->zero_size = lst->prec - lst->len;
	lst->cnt += lst->left_size + lst->zero_size + lst->sign + lst->len;
	ft_flag_print(lst->left_size, ' ');
	ft_flag_print(lst->zero_size, '0');
	ft_res_print_p(lst);
}

void	ft_pflag_on(t_lst *lst)
{
	if (lst->left)
	{
		lst->cnt += lst->left_size + lst->zero_size + lst->len;
		ft_flag_print(lst->zero_size, '0');
		ft_res_print_p(lst);
		ft_flag_print(lst->left_size, ' ');
	}
	else if (lst->zero)
	{
		if (!(lst->zero_size) && !(lst->dot))
			lst->zero_size = lst->width - lst->len;
		else if (lst->dot)
		{
			lst->cnt += lst->left_size;
			ft_flag_print(lst->left_size, ' ');
		}
		lst->cnt += lst->zero_size + lst->len;
		ft_flag_print(lst->zero_size, '0');
		ft_res_print_p(lst);
	}
}

void	ft_print_p(t_lst *lst)
{
	if (lst->dot && !(lst->prec) && !(lst->res))
		lst->len = 2;
	if ((lst->width <= lst->len) && (lst->prec <= lst->len))
	{
		ft_res_print_p(lst);
		lst->cnt += lst->len;
		return ;
	}
	lst->zero_size = lst->len < lst->prec ? lst->prec - lst->len : 0;
	if ((lst->prec < lst->width) && (lst->len < lst->width))
		lst->left_size = (lst->len < lst->prec) ? lst->width - lst->prec
												: lst->width - lst->len;
	(lst->left || lst->zero) ? ft_pflag_on(lst) : ft_pflag_off(lst);
}
