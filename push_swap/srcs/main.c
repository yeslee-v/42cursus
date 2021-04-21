/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:54 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/21 22:14:51 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac == 1)
		ft_error_message();
	int i = 0;
	while (av[++i])
	{
		//printf("%d : %s|%d|\n", i, av[i], ft_check_atoi(av[i]));
		printf("=============\n");
		printf("len:%d\n", ft_check_same(av));
	}
	return (0);
}
