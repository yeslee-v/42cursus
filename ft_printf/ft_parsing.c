/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:38:00 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/13 12:05:29 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_type(const char *str)
{
	if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd' ||
		*str == 'i' || *str == 'u' || *str == 'x' || *str == 'X' || *str == '%')
		return (0);
	return (1);
}

void		ft_flag(const char *str, t_list *lst)
{
	if (*str == '-')
		lst->left = 1;
	else if (*str == '0')
		lst->zero = 1;
}

int			ft_if_star(const char *str, int num, va_list ap)
{
	if (*str == '*')
	{
		num = va_arg(ap, int);
		str++;
	}
	else
	{
		while (*str != '.' && ft_type(str))
		{
			num = (num * 10) + (*str - '0');
			str++;
		}
	}
	return (num);
}

int			ft_input_w_p(const char **str, int num, va_list ap)
{
	if (ft_atoi((char *)str) || **str == '*')
	{
		num = ft_if_star(*str, num, ap);
		if (**str != '*')
		{
			// lst->cnt += ft_intlen(num);
			*str += ft_intlen(num);
		}
		else
		{
			// lst->cnt++;
			**str++;
		}
	}
	return (num);
}

const char	*ft_parsing(const char *str, t_list *lst, va_list ap)
{
	while (*str == '-' || *str == '0')
	{
		ft_flag(str, lst);
		lst->cnt++;
		str++;
	}
	lst->width = ft_input_w_p(&str, lst->width, ap);
	if (*str == '.')
	{
		str++;
		lst->cnt++;
		lst->prec = ft_input_w_p(&str, lst->prec, ap);
	}
	if (ft_type(str))
	{
		lst->cnt++;
		str++;
	}
	return (str);
}
