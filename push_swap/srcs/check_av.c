/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:54:54 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/22 16:57:46 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_atoi(char *s)
{
	int		i;
	int		ret;

	i = 0;
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			ft_error_message();
		i++;
	}
	ret = ft_atoi(s);
	return (ret);
}

int		ft_double_strlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_check_same(char **av)
{
	int i;
	int j;
	int	len;

	len = ft_double_strlen(av) - 1;
	i = 0;
	while (av[++i])
	{
		j = i;
		while (av[++j])
		{
			printf("%d\n", ft_check_atoi(av[i]));
			if (ft_check_atoi(av[i]) == ft_check_atoi(av[j]))
				ft_error_message();
		}
	}
	return (len);
}
