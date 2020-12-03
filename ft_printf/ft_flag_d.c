/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:29:15 by yeslee            #+#    #+#             */
/*   Updated: 2020/12/03 22:04:05 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_flag_d(t_list *lst)
{
	if (lst->left == 1)
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
	else if (lst->zero == 1)
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
}
