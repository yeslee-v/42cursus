/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:29:15 by yeslee            #+#    #+#             */
/*   Updated: 2020/12/03 17:35:59 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_flag_d(t_list *lst)
{
	printf("in_width: %d\n", lst->width);
	printf("in_len: %d\n", lst->len);
	if (lst->left == 1)
	{
		if (lst->width > lst->len)
		{
			write(1, ft_itoa(lst->result), lst->len);
			while (lst->width > lst->len)
			{
				write(1, " ", 1);
				lst->width--;
				printf("width: %d\n", lst->width);
				printf("len: %d\n", lst->len);
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
				printf("width_2: %d\n", lst->width);
				printf("len_2: %d\n", lst->len);
			}
			write(1, ft_itoa(lst->result), lst->len);
		}
	}
}
