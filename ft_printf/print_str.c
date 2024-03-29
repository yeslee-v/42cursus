/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:07:46 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/29 01:00:42 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_res_print_s(t_lst *lst)
{
	if (lst->res_s == NULL)
		lst->res_s = "(null)";
	if (!(lst->dot))
	{
		ft_putstr(lst->res_s);
		return ;
	}
	((lst->prec) && (lst->prec < lst->len)) ? ft_putnstr(lst->prec, lst->res_s)
											: ft_putstr(lst->res_s);
	if ((lst->res_s == NULL) || (lst->dot && !(lst->prec)))
		free(lst->res_s);
}

void	ft_sflag_off(t_lst *lst)
{
	ft_flag_print(lst->left_size, ' ');
	ft_res_print_s(lst);
}

void	ft_sflag_on(t_lst *lst)
{
	if (lst->zero)
	{
		lst->zero_size = lst->width - lst->len;
		ft_flag_print(lst->zero_size, '0');
		ft_res_print_s(lst);
		return ;
	}
	ft_res_print_s(lst);
	ft_flag_print(lst->left_size, ' ');
}

void	ft_set_size(t_lst *lst)
{
	if (lst->len < lst->width)
	{
		if (!(lst->dot))
			lst->left_size = lst->width - lst->len;
		else if (lst->prec <= lst->width)
			lst->left_size = ((lst->len <= lst->prec) ?
					lst->width - lst->len : lst->width - lst->prec);
		else
			lst->left_size = lst->width - lst->len;
	}
	else if ((lst->width <= lst->len) && (lst->prec < lst->len))
		lst->left_size = (lst->dot) ? lst->width - lst->prec : lst->width;
	if (lst->left_size < 0)
		lst->left_size = 0;
}

void	ft_print_str(t_lst *lst)
{
	if (lst->res_s == NULL)
		lst->res_s = ft_strdup("(null)");
	if (lst->dot && !(lst->prec))
		lst->res_s = ft_strdup("");
	lst->len = ft_strlen(lst->res_s);
	if ((lst->dot && !(lst->prec)) || !(lst->len))
	{
		ft_flag_print(lst->width, ' ');
		lst->cnt += lst->width;
		return ;
	}
	else if ((lst->width <= lst->len) && ((!(lst->dot)) || (lst->prec == 0)))
	{
		ft_res_print_s(lst);
		lst->cnt += lst->len;
		return ;
	}
	ft_set_size(lst);
	if (lst->dot)
		lst->cnt += ((lst->len <= lst->prec)) ? lst->left_size + lst->len
												: lst->left_size + lst->prec;
	else
		lst->cnt += lst->left_size + lst->len;
	(lst->left || lst->zero) ? ft_sflag_on(lst) : ft_sflag_off(lst);
}
