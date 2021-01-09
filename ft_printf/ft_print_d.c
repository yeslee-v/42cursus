/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:43:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/10 00:01:32 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_res(t_list *lst)
{
	write(1, ft_itoa(lst->result), lst->len);
}

void	ft_width_len(t_list *lst)
{
	// printf("lst:%d %d %d\n\n", lst->width, lst->prec, lst->len);
	if (lst->len < lst->width)
	{
		if ((lst->left) || (lst->left && lst->zero))
		{
			while (lst->prec > lst->len)
			{
				printf("[0]\n");
				write(1, "0", 1);
				lst->prec--;
			}
			ft_write_res(lst);
			if ((lst->width > lst->len) && (lst->prec > lst->len))
				return ;
		}
		while (lst->len < lst->width)
		{
			if (!(lst->left) && lst->zero)
			{
				if (lst->result < 0)
				{
					write(1, "-", 1);
					lst->result *= -1;
					lst->len--;
				}
				write(1, "0", 1);
			}
			else
			{
				if (lst->prec <= lst->len)
				{
					if (lst->prec <= lst->width)
					{
						write(1, " ", 1);
						//printf("[1]\n");
					}
					else
					{
						//printf("[2]\n");
					}
				}
				else
				{
					if (lst->prec < lst->width)
					{
						write(1, " ", 1);
						//printf("[3]\n");
					}
					else
					{
						write(1, "0", 1);
						//printf("[4]\n");
					}
				}
			}
			lst->width--;
		}
		if (!((lst->left) || (lst->left && lst->zero)))
			ft_write_res(lst);
	}
	else
	{
		if (lst->prec <= lst->len)
		{
			if (lst->prec < lst->width)
			{
				//write(1, " ", 1);
				//printf("[5]\n");
			}
			else
			{
				//printf("[6]\n");
			}
		}
		else
		{
			if (lst->prec < lst->width)
			{
				//write(1, " ", 1);
				//printf("[7]\n");
			}
			else
			{
				//write(1, "0", 1);
				//printf("[8]\n");
			}
		}
		if (lst->len == lst->width)
			ft_write_res(lst);
	}
}

void	ft_print_d(t_list *lst)
{
	if (lst->result < 0)
		lst->len++;
	ft_width_len(lst);
}
