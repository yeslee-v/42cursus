/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:43:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/08 23:40:05 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_res(t_list *lst)
{
	write(1, ft_itoa(lst->result), lst->len);
}

void	ft_width_len(t_list *lst)
{
	int	big;
	int	small;

		if (lst->width > lst->prec)
		{
			big = lst->width;
			small = lst->prec;
		}
		else
		{
			big = lst->prec;
			small = lst->width;
		}
	if (big > lst->len)
	{
		if ((lst->left) || (lst->left && lst->zero))
			ft_write_res(lst);
		while (big > lst->len)
		{
			if (!(lst->left) && lst->zero)
			{
				if (lst->result < 0)
				{
					write(1, "-", 1);
					lst->result *= -1;
				}
				write(1, "0", 1);
			}
			else
			{
				if (lst->width > lst->prec)
				{
					write(1, " ", 1);
					lst->width--;
				}
				else
				{
					if ((lst->prec - lst->len))
					{
						write(1, "0", 1);
						small--;
					}
				}
			}
			big--;
		}
		if (!((lst->left) || (lst->left && lst->zero)))
			ft_write_res(lst);
	}
	else
	{
		if (lst->len < small)
		{
			while (small > lst->len)
			{
				write(1, "0", 1);
				small--;
			}
			ft_write_res(lst);
		}
		else
			ft_write_res(lst);
	}
}

void	ft_print_d(t_list *lst)
{
	if (lst->result < 0)
		lst->len++;
	ft_width_len(lst);
}
