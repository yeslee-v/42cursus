/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wid_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:55:52 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/23 00:08:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_input_wid_prec(const char **str, int w_p, va_list *ap)
{
	if (**str == '*')
	{
		w_p = va_arg(*ap, int);
		(*str)++;
	}
	else
	{
		while (ft_atoi(*str) || **str == '0')
		{
			w_p = (w_p * 10) + (**str - '0');
			(*str)++;
		}
	}
	return (w_p);
}

void	ft_check_width(const char **str, t_lst *lst, va_list *ap)
{
	if (**str == '*' || **str == '0' || ft_atoi(*str))
	{
		lst->width = ft_input_wid_prec(str, lst->width, ap);
		if (lst->width < 0)
		{
			lst->left = 1;
			lst->zero = 0;
			lst->width *= -1;
		}
	}
}

void	ft_check_prec(const char **str, t_lst *lst, va_list *ap)
{
	if (**str == '.')
	{
		lst->dot = 1;
		(*str)++;
		lst->prec = ft_input_wid_prec(str, lst->prec, ap);
		if (lst->prec < 0)
			lst->prec = -1;
	}
}
