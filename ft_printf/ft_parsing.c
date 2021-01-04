/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:38:00 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/04 10:47:59 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	ft_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (c);
	return ('0');
}

const char	*ft_parsing(const char *str, t_list *lst)
{
	if (ft_type(*str) == '0')
	{
		if (*str == '-')
			lst->left = 1;
		else if (*str == '0')
			lst->zero = 1;
		while (*str == '-' || *str == '0')
    		str++;
		//printf("str: %c\n", *str);
		while (ft_atoi((char *)str))
		{
			lst->width = (lst->width * 10) + (*str - '0');
			//printf("width: %d\n", lst->width);
			str++;
		}
		if (*str == '.')
		{
			str++;
			while (ft_atoi((char *)str))
			{
				lst->prec = (lst->prec * 10) + (*str - '0');
				str++;
			}
		}
	}
	if (ft_type(*str))
		lst->type = *str;
	return (str);
}
