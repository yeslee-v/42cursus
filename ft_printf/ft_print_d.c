/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:43:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/05 22:52:45 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_d(t_list *lst)
{
	printf("len:%d\n", lst->len);
	if (lst->result < 0)
		lst->len++;
	if (lst->left)
	{
		if (lst->width > lst->len)
		{
			write(1, ft_itoa(lst->result), lst->len);
			while (lst->width > lst->len)
			{
				write(1, " ", 1);
				lst->width--;
			}
		}
	}
	else if (lst->zero)
	{
		if (lst->width > lst->len)
		{
			while (lst->width > lst->len)
			{
				write(1, "0", 1);
				lst->width--;
			}
			write(1, ft_itoa(lst->result), lst->len);
		}
	}
	else if (lst->width)
	{
		if (lst->width > lst->len)
		{
			while (lst->width > lst->len)
			{
				write(1, " ", 1);
				lst->width--;
			}
			write(1, ft_itoa(lst->result), lst->len);
		}
	}
}
