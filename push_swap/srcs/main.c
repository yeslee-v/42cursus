/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:54 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/06 17:28:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_node(t_lst *stack)
{
	t_node *tmp;

	tmp = stack->head;
	if (tmp == NULL)
	{
		printf("element is not exist\n");
		return ;
	}
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
	t_stack	stack;

	stack.a = ft_init_list(stack.a);
	stack.b = ft_init_list(stack.b);
	ft_check_error(ac);

	i = 0;
	while (av[++i])
		ft_node_init(stack.a, ft_check_same(&av[i]));
	if (!(ft_strncmp(av[0], "./checker", ft_strlen(av[0]))))
		ft_read(stack.a, stack.b);
	if (!(ft_strncmp(av[0], "./push_swap", ft_strlen(av[0]))))
		ft_quick_sort_init(&stack, 0, ac - 1);
	return (0);
}
