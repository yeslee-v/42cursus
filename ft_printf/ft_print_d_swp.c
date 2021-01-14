/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_swp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:43:34 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/14 22:37:36 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_negative(t_lst *lst)
{
	if (lst->result < 0)
	{
		write(1, "-", 1);
		lst->result *= -1;
		lst->len--;
	}
	return ;
}

void	ft_width_len(t_lst *lst)
{
	if (lst->left) // -
	{
		if (lst->len < lst->width)
		{
			if (lst->prec <= lst->len)
			{
				write(1, ft_itoa(lst->result), lst->len);
				if (lst->prec <= lst->width)
				{
					while (lst->len < lst->width)
					{
						write(1, " ", 1);
						lst->width--;
					}
				}
			}
			else // len > prec
			{
				if (lst->prec <= lst->width)
				{
					write(1, ft_itoa(lst->result), lst->len);
					while (lst->len <= lst->width)
					{
						write(1, " ", 1);
						lst->width--;
					}
				}
				else // width < prec
				{
					ft_negative(lst);
					while (lst->len < lst->prec)
					{
						write(1, "0", 1);
						lst->prec--;
					}
					write(1, ft_itoa(lst->result), lst->len);
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
				}
				write(1, ft_itoa(lst->result), lst->len);
			}
			else // len < prec
			{
				if (lst->prec <= lst->width)
					write(1, " ", 1);
				else
				{
					while (lst->len < lst->prec)
					{
						write(1, "0", 1);
						lst->prec--;
					}
				}
				write(1, ft_itoa(lst->result), lst->len);
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
				}
				else
					write(1, "0", 1);
			}
			else
			{
				if (lst->prec <= lst->width)
					write(1, " ", 1);
				else
				{
					while (lst->len < lst->prec)
					{
						write(1, "0", 1);
						lst->prec--;
					}
				}
			}
			write(1, ft_itoa(lst->result), lst->len);
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
				}
				write(1, ft_itoa(lst->result), lst->len);
				ft_write_res(lst);
			}
			else // len < prec
			{
				if (lst->prec <= lst->width)
					write(1, " ", 1);
				else
				{
					while (lst->len < lst->prec)
					{
						write(1, "0", 1);
						lst->prec--;
					}
				}
				write(1, ft_itoa(lst->result), lst->len);
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
				}
				ft_negative(lst);
				while (lst->len < lst->prec)
				{
					write(1, "0", 1);
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
				}
			}
			else // len < prec
			{
				ft_negative(lst);
				if (lst->prec <= lst->width)
					write(1, " ", 1);
				else
				{
					while (lst->len < lst->prec)
					{
						write(1, "0", 1);
						lst->prec--;
					}
				}
			}
		}
		write(1, ft_itoa(lst->result), lst->len);
	}
}

void	ft_print_d(t_lst *lst)
{
	if (lst->prec <= lst->len && lst->width <= lst->len)
		lst->cnt += lst->len;
	else
	{
		if (lst->width <= lst->prec)
			lst->cnt += ft_size(lst->prec);
		else
			lst->cnt += ft_size(lst->width);
	}
	if (lst->result < 0)
		lst->len++;
	ft_width_len(lst);
}
