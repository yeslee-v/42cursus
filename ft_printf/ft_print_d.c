/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:43:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/10 17:54:53 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_res(t_list *lst)
{
	write(1, ft_itoa(lst->result), lst->len);
}

void	ft_negative(t_list *lst)
{
	if (lst->result < 0)
	{
		write(1, "-", 1);
		lst->result *= -1;
		lst->len--;
	}
	return ;
}

void	ft_width_len(t_list *lst)
{
	if ((lst->left) || (lst->left && lst->zero)) // -
	{
		if (lst->len < lst->width)
		{
			if (lst->prec <= lst->len)
			{
				ft_write_res(lst);
				if (lst->prec <= lst->width)
				{
					while (lst->len < lst->width)
					{
						write(1, " ", 1);
						lst->width--;
					}
					// printf("[1]\n");
				}
				else
				{
					// printf("[2]\n");
				}
			}
			else // len > prec
			{
				if (lst->prec <= lst->width)
				{
					ft_write_res(lst);
					while (lst->len <= lst->width)
					{
						write(1, " ", 1);
						lst->width--;
						// printf("[3]\n");
					}
				}
				else	// width < prec
				{
					ft_negative(lst);
					while (lst->len < lst->prec)
					{
						write(1, "0", 1);
						// printf("[4]\n");
						lst->prec--;
					}
					ft_write_res(lst);
				}
			}
		}
		else // width <= len
		{
			if (lst->prec <= lst->len)
			{
				if (lst->prec <= lst->width)
				{
					while (lst->len < lst->width)
					{
						write(1, " ", 1);
						lst->width--;
					}
					// printf("[1-1]\n");
				}
				else
				{
					// printf("[2-1]\n");
				}
				ft_write_res(lst);
			}
			else // len < prec
			{
				if (lst->prec <= lst->width)
				{
					write(1, " ", 1);
					// printf("[3-1]\n");
				}
				else
				{
					while (lst->len < lst->prec)
					{
						write(1, "0", 1);
						//	printf("[4-1]\n");
						lst->prec--;
					}
				}
				ft_write_res(lst);
			}
		}
	}
	else if (!(lst->left) && lst->zero) // 0
	{
		if (lst->len < lst->width)
		{
			if (lst->prec <= lst->len)
			{
				if (lst->prec <= lst->width)
				{
					while (lst->len < lst->width)
					{
						write(1, "0", 1);
						lst->width--;
					}
					//	printf("[5]\n");
				}
				else
				{
					write(1, "0", 1);
					// printf("[6]\n");
				}
			}
			else
			{
				if (lst->prec <= lst->width)
				{
					write(1, " ", 1);
					// printf("[7]\n");
				}
				else
				{
					while (lst->len < lst->prec)
					{
						write(1, "0", 1);
						//	printf("[8]\n");
						lst->prec--;
					}
				}
			}
			ft_write_res(lst);
		}
		else // width <= len
		{
			if (lst->prec <= lst->len)
			{
				if (lst->prec <= lst->width)
				{
					while (lst->len < lst->width)
					{
						write(1, " ", 1);
						lst->width--;
					}
					// printf("[5-1]\n");
				}
				else
				{
					// printf("[6-1]\n");
				}
				ft_write_res(lst);
			}
			else // len < prec
			{
				if (lst->prec <= lst->width)
				{
					write(1, " ", 1);
					// printf("[7-1]\n");
				}
				else
				{
					while (lst->len < lst->prec)
					{
						write(1, "0", 1);
						// printf("[8-1]\n");
						lst->prec--;
					}
				}
				ft_write_res(lst);
			}
		}
	}
	else // none flag
	{
		if (lst->len < lst->width)
		{
			if (lst->prec <= lst->len)
			{
				if (lst->prec <= lst->width)
				{
					while (lst->len < lst->width)
					{
						write(1, " ", 1);
						lst->width--;
					}
					// printf("[9]\n");
				}
				else
				{
					// printf("[10]\n");
				}
			}
			else // len < prec
			{
				if (lst->prec <= lst->width)
				{
					if (lst->result < 0)
						lst->width--;
					while (lst->prec < lst->width)
					{
						write(1, " ", 1);
						lst->width--;
					}
					// printf("[11]\n");
				}
				ft_negative(lst);
				while (lst->len < lst->prec)
				{
					write(1, "0", 1);
					//printf("[12]\n");
					lst->prec--;
				}
			}
		}
		else // width <= len
		{
			if (lst->prec <= lst->len)
			{
				if (lst->prec <= lst->width)
				{
					while (lst->len < lst->width)
					{
						write(1, " ", 1);
						lst->width--;
					}
					// printf("[9-1]\n");
				}
				else
				{
					// printf("[10-1]\n");
				}
			}
			else // len < prec
			{
				ft_negative(lst);
				if (lst->prec <= lst->width)
				{
					write(1, " ", 1);
					// printf("[11-1]\n");
				}
				else
				{
					while (lst->len < lst->prec)
					{
						write(1, "0", 1);
						// printf("[12-1]\n");
						lst->prec--;
					}
				}
			}
		}
		ft_write_res(lst);
	}
}

void	ft_print_d(t_list *lst)
{
	if (lst->result < 0)
		lst->len++;
	ft_width_len(lst);
}
