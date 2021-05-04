/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:54 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/04 18:26:45 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_node(t_lst *stack)
{
	t_node *tmp;

	tmp = stack->head;
	printf("\n");
	while (tmp)
	{
		printf(" | %d |\n", tmp->data);
		tmp = tmp->next;
		if (tmp == stack->head)
		{
			printf(" -----\n");
			break ;
		}
	}
//	printf("%d\n", stack->res);
	printf("====================\n");
/*	printf("====================\n");
	tmp = stack->tail;
	printf("\n");
	while (tmp)
	{
		printf(" { %d }\n", tmp->data);
		tmp = tmp->prev;
		if (tmp == stack->tail)
		{
			printf(" +++++++\n");
			break ;
		}
	}*/
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
	ft_read(lst_a, lst_b);
	//ft_set_pivot(lst_a, lst_b);
	return (0);
}
