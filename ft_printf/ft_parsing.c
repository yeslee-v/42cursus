/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:38:00 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/06 17:47:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int			ft_type(const char *str, t_list *lst)
{
	if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd' ||
		*str == 'i' || *str == 'u' || *str == 'x' || *str == 'X' || *str == '%')
	{
		lst->type = *str;
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

const char	*ft_parsing(const char *str, t_list *lst, va_list ap)
{
	if (ft_type(str, lst))
	{
		while (*str == ' ' || *str == '+' || *str == '-' || *str == '0')
		{
			ft_flag(str, lst);
			str++;
		}
		if (*str == '*')
		{
			lst->width = va_arg(ap, int);
			str++;
		}
		else
		{
			while (ft_atoi((char *)str))
			{
				lst->width = (lst->width * 10) + (*str - '0');
				str++;
			}
		}
		if (*str == '.')
		{
			str++;
			if (*str == '*')
			{
				lst->prec = va_arg(ap, int);
				printf("what:%d\n", lst->prec);
			}
			else
			{
				while (ft_atoi((char *)str))
				{
					lst->prec = (lst->prec * 10) + (*str - '0');
					str++;
				}
			}
		}
	}
	else
		ft_type(str, lst);
	return (str);
}
