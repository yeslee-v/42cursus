/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:57:09 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/27 01:22:15 by yeslee           ###   ########.fr       */
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
	}
}

void	ft_res_print_d(t_lst *lst)
{
	char	*res;

	res = "0";
	if ((lst->dot && !(lst->prec)) && !(lst->res))
		return ;
	else
	{
		if (lst->type == 'd' || lst->type == 'i')
			res = ft_itoa(lst->res);
		else if (lst->type == 'u')
			res = ft_itoa_base(lst->res, 10, lst->type);
		else if ((lst->type == 'x') || (lst->type == 'X'))
			res = ft_itoa_base(lst->res, 16, lst->type);
		ft_putstr(res);
		free(res);
	}
}

void	ft_dflag_off(t_lst *lst)
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
	ft_res_print_d(lst);
}

void	ft_dflag_on(t_lst *lst)
{
	if (lst->left)
	{
		lst->cnt += lst->left_size + lst->zero_size + lst->sign + lst->len;
		ft_neg_to_pos(lst);
		ft_flag_print(lst->zero_size, '0');
		ft_res_print_d(lst);
		ft_flag_print(lst->left_size, ' ');
	}
	else if (lst->zero)
	{
		if (!(lst->zero_size) && !(lst->dot))
			lst->zero_size = lst->width - lst->len;
		if (lst->dot)
		{
			lst->cnt += lst->left_size;
			ft_flag_print(lst->left_size, ' ');
		}
		lst->cnt += lst->zero_size + lst->sign + lst->len;
		ft_neg_to_pos(lst);
		ft_flag_print(lst->zero_size, '0');
		ft_res_print_d(lst);
	}
}

void	ft_print_num(t_lst *lst)
{
	if (!(lst->res) && lst->dot && !(lst->prec))
		lst->len = 0;
	else if ((lst->width <= lst->len) && (lst->prec <= lst->len))
	{
		ft_res_print_d(lst);
		lst->cnt += lst->len;
		return ;
	}
	lst->zero_size = lst->len < lst->prec ? lst->prec - lst->len : 0;
	if ((lst->prec < lst->width) && (lst->len < lst->width))
		lst->left_size = (lst->len < lst->prec) ? lst->width - lst->prec
												: lst->width - lst->len;
	if (!(lst->dot))
		lst->left_size = lst->width - lst->len;
	(lst->left || lst->zero) ? ft_dflag_on(lst) : ft_dflag_off(lst);
}
