/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:07:46 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/25 00:57:43 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_res_print_s(t_lst *lst)
{
	if (lst->res_s == NULL)
	{
		lst->res_s = "(null)";
		if (lst->prec == -1)
			ft_putstr(lst->res_s);
	}
	else if (lst->prec == -1)
	{
		ft_putstr(lst->res_s);
		return ;
	}
	((lst->prec) && (lst->prec < lst->len)) ? ft_putnstr(lst->prec, lst->res_s)
											: ft_putstr(lst->res_s);
}

void	ft_sflag_off(t_lst *lst)
{
	ft_flag_print(lst->left_size, ' ');
	ft_res_print_s(lst);
}

void	ft_sflag_on(t_lst *lst)
{
	ft_res_print_s(lst);
	ft_flag_print(lst->left_size, ' ');
}

void	ft_set_size(t_lst *lst)
{
	if (lst->len < lst->width)
	{
		if (!(lst->dot) || (lst->prec == -1))
			lst->left_size = lst->width - lst->len;
		else if (lst->prec <= lst->width)
			lst->left_size = ((lst->len <= lst->prec) ?
					lst->width - lst->len : lst->width - lst->prec);
		else
			lst->left_size = lst->width - lst->len;
	}
	else
	{
		if (lst->prec < lst->len)
			lst->left_size = (lst->prec == -1) ? lst->width
												: lst->width - lst->prec;
	}
}

void		ft_print_str(t_lst *lst)
{
	if ((lst->dot && !(lst->prec)) || !(lst->len))
	{
		ft_flag_print(lst->width, ' ');
		return ;
	}
	else if (((lst->width <= lst->len) && (lst->prec <= 0)))
	{
		ft_res_print_s(lst);
		lst->cnt += lst->len;
		return ;
	}
	ft_set_size(lst);
	lst->cnt += (lst->len <= lst->prec) ? lst->left_size + lst->len
										: lst->left_size + lst->prec;
	lst->left ? ft_sflag_on(lst) : ft_sflag_off(lst);
}
