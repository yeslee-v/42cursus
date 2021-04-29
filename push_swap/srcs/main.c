/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:54 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/29 17:05:39 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_node(t_lst *stack)
{
	t_node *tmp;

	tmp = stack->tail;
	printf("\n");
	while (tmp)
	{
		printf(" | %d |\n", tmp->data);
		tmp = tmp->prev;
		if (tmp == stack->tail)
		{
			printf(" -----\n");
			break ;
		}
	}
	printf("====================\n");
}

int main(int ac, char **av)
{
	int		i;
	t_lst	*lst_a;
	t_lst	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	lst_a = ft_init_list(lst_a);
	lst_b = ft_init_list(lst_b);
	ft_check_error(ac);
	
	i = 0;
	while (av[++i])
		ft_node_init(lst_a, ft_check_same(&av[i]));
	ft_set_pivot(lst_a);
	return (0);
}
