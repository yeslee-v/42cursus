/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wid_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:55:52 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/27 00:24:12 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_input_wid_prec(const char **str, va_list *ap)
{
	int	w_p;

	w_p = 0;
	if (**str == '*')
	{
		w_p = va_arg(*ap, int);
		(*str)++;
	}
	else
	{
		if (ft_isdigit(**str) || **str == '-')
		{
			w_p = ft_atoi(*str);
			if (**str == '-')
				(*str)++;
			while (ft_isdigit(**str))
				(*str)++;
		}
	}
	return (w_p);
}

void	ft_check_width(const char **str, t_lst *lst, va_list *ap)
{
	if (**str == '*' || **str == '-' || ft_isdigit(**str))
	{
		lst->width = ft_input_wid_prec(str, ap);
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
		lst->prec = ft_input_wid_prec(str, ap);
		if (lst->prec < 0)
			lst->dot = 0;
	}
}
