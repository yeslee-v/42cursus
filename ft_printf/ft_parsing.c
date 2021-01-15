/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:38:00 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/15 11:18:12 by yeslee           ###   ########.fr       */
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

int			ft_if_star(const char *str, int n, va_list ap)
{
	if (*str == '*')
		n = va_arg(ap, int);
	else
	{
		while (*str != '.' && ft_type(str))
		{
			n = (n * 10) + (*str - '0');
			str++;
		}
	}
	return (n);
}

int			ft_input_w_p(const char **str, int num, va_list ap)
{
	num = ft_if_star(*str, num, ap);
	if (**str != '*')
		*str += ft_size(num);
	else
		(*str)++;
	return (num);
}

const char	*ft_parsing(const char *str, t_lst *lst, va_list ap)
{
	while (*str == '-' || *str == '0')
	{
		if (*str == '-')
			lst->left = 1;
		else if (*str == '0')
			if (!(lst->left))
				lst->zero = 1;
		lst->cnt++;
		str++;
	}
	if (ft_atoi((char *)str) || *str == '*')
		lst->width = ft_input_w_p(&str, lst->width, ap);
	if (*str == '.')
	{
		str++;
		if (ft_atoi((char *)str) || *str == '*')
			lst->prec = ft_input_w_p(&str, lst->prec, ap);
	}
	if (ft_type(str))
		str++;
	return (str);
}
