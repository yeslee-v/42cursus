/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:33:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/13 19:32:40 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_check_flow(int sign, long tmp)
{
	if (((sign * tmp) < -2147483648) || ((sign * tmp) > 2147483647))
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
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
		if (ft_check_flow(sign, tmp))
			return (0);
		tmp = (tmp * 10) + (*str - '0');
		str++;
	}
	return (sign * (int)tmp);
}
