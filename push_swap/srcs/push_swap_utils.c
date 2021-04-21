/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:52:28 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/21 22:14:44 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_message()
{
	write(2, "Error\n", 6);
	exit(0);
}

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
			if (av[i] == av[j])
				ft_error_message(); // error
			printf("%s : %s\n", av[i], av[j]);
		}
	}
	return (len);
}
