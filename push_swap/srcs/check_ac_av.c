/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ac_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:50:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/08 14:57:42 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_atoi(char *s)
{
	int		i;
	int		ret;
	int		minus;

	i = 0;
	minus = 0;

	if ((ft_atoi(s) >= 2147483648) || (ft_atoi(s) <= -2147483649))
		ft_error_message();
	while (s[i])
	{
		if (s[i] == '-')
			i++;
		if (!(ft_isdigit(s[i])))
			ft_error_message();
		i++;
	}
	ret = ft_atoi(s);
	return (ret);
}

int		ft_check_same(char **av)
{
	int i;
	int j;

	i = -1;
	while (av[++i])
	{
		j = i;
		while (av[++j])
		{
			if (ft_check_atoi(av[i]) == ft_check_atoi(av[j]))
				ft_error_message();
		}
	}
	return (ft_check_atoi(*av));
}
