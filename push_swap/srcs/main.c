/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:54 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/23 15:22:05 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac == 1)
		ft_error_message();
	else if (ac == 2)
	{
		if (EOF)
			ft_ok();
	}
	int i = 0;
	while (av[++i])
		//printf("len:%d|%s\n", ft_check_same(av), av[i]);
		printf("len:%s\n", av[i]);
	return (0);
}
