/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:33:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/08 15:01:02 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atoi(const char *str)
{
	int		sign;
	long	tmp;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	tmp = 0;
	while ((*str >= '0') && (*str <= '9'))
	{
		tmp = (tmp * 10) + (*str - '0');
		str++;
	}
	return (sign * tmp);
}
