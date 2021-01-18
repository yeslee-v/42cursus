/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wid_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:55:52 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/19 00:37:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_input_wid_prec(const char **str, int w_p, va_list *ap)
{
	if (**str == '*')
		w_p = va_arg(*ap, int);
	else if (ft_atoi((char *)str))
	{
		while (**str != '.' && !(ft_istype(*str)))
		{
			w_p = (w_p * 10) + (**str - '0');
			(*str)++;
		}
	}
	return (w_p);
}

int		ft_move_str(const char **str, int num, va_list *ap)
{
	num = ft_input_wid_prec(str, num, ap);
	(**str != '*') ? *str += ft_size(num) : (*str)++;
	return (num);
}

void	ft_check_width(const char **str, t_lst *lst, va_list *ap)
{
	if (**str == '*' || ft_atoi((char *)str))
	{
		lst->width = ft_move_str(str, lst->width, ap);
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
		(*str)++;
		lst->prec = ft_move_str(str, lst->prec, ap);
	}
	printf("\n\nstr:%c\n\n", **str);
}
