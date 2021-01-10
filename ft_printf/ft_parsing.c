/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:38:00 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/10 21:33:12 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_type(const char *str, char type)
{
	if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd' ||
		*str == 'i' || *str == 'u' || *str == 'x' || *str == 'X' || *str == '%')
	{
		type = *str;
		return (0);
	}
	return (1);
}

void		ft_flag(const char *str, t_list *lst)
{
	if (*str == ' ')
		lst->space = 1;
	else if (*str == '+')
		lst->plus = 1;
	else if (*str == '-')
		lst->left = 1;
	else if (*str == '0')
		lst->zero = 1;
}

int			ft_parsing_star(const char *str, int num, va_list ap, char type)
{
	if (*str == '*')
	{
		num = va_arg(ap, int);
		str++;
	}
	else
	{
		while (*str != '.' && ft_type(str, type))
		{
			num = (num * 10) + (*str - '0');
			str++;
		}
	}
	return (num);
}

const char	*ft_parsing(const char *str, t_list *lst, va_list ap)
{
	if (ft_type(str, lst->type))
	{
		while (*str == ' ' || *str == '+' || *str == '-' || *str == '0')
		{
			ft_flag(str, lst);
			str++;
		}
		lst->width = ft_parsing_star(str, lst->width, ap, lst->type);
		while (*str != '.')
			str++;
		//printf("str:%c\n\n", *str);
		if (*str == '.')
		{
			str++;
			if (ft_type(str, lst->type))
			{
				lst->prec = ft_parsing_star(str, lst->prec, ap, lst->type);
				if (*str == '*')
					str++;
			}
		}
	}
	if (ft_type(str, lst->type))
		str++;
	return (str);
}
