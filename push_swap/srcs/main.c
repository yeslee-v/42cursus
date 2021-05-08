/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:54 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/08 12:25:08 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_node(t_lst *stack)
{
	t_node *tmp;

	tmp = stack->head;
	if (tmp == NULL)
	{
		printf(" |  |\n");
		printf(" ---\n");
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
	printf("====================\n");
}

int main(int ac, char **av)
{
	int		i;
	t_stack	stack;

	i = 0;
	if (ac == 1)
		ft_error_message();
	stack.a = ft_init_list(stack.a);
	stack.b = ft_init_list(stack.b);
	while (av[++i])
		ft_node_init(stack.a, ft_check_same(&av[i]));
	if (!(ft_strncmp(av[0], "./checker", ft_strlen(av[0]))))
		ft_read(stack.a, stack.b);
	if (!(ft_strncmp(av[0], "./push_swap", ft_strlen(av[0]))))
		ft_quick_sort_init(&stack, 0, ac - 1);
	return (0);
}
