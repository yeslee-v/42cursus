/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:38:00 by yeslee            #+#    #+#             */
/*   Updated: 2020/12/03 16:47:43 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_parsing(const char *str)
{
	t_list	*lst;

	if (ft_type(*str) == '0')
	{
		if (*str == '-')
			lst->left = 1;
		else if (*str == '0')
			lst->zero = 1;
		while (*str == '-' || *str == '0')
    		str++;
		while (ft_atoi((char *)str))
		{
			lst->width = (lst->width * 10) + (*str - '0');
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
