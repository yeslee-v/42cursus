/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:43:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/06 22:50:28 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_res(t_list *lst)
{
	write(1, ft_itoa(lst->result), lst->len);
}

void	ft_width_len(t_list *lst)
{
	if (lst->width > lst->len)
	{
		if ((lst->left) || (lst->left && lst->zero))
			ft_write_res(lst);
		while (lst->width > lst->len)
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
				write(1, " ", 1);
			lst->width--;
		}
		if (!((lst->left) || (lst->left && lst->zero)))
			ft_write_res(lst);
	}
}

void	ft_print_d(t_list *lst)
{
	if (lst->result < 0)
		lst->len++;
	ft_width_len(lst);
}
