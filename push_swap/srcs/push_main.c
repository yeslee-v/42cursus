/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:58:08 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/08 22:03:38 by yeslee           ###   ########.fr       */
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

int		ft_lstcnt(t_lst *lst)
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = lst->head;
	while (node)
	{
		cnt++;
		node = node->next;
		if (node == lst->head)
			break ;
	}
	return (cnt);
}

int main(int ac, char **av)
{
	int		i;
	t_stack	stack;

	if (ac == 1)
		exit(0);
	i = 0;
	stack.a = ft_init_list(stack.a);
	stack.b = ft_init_list(stack.b);
	while (av[++i])
		ft_node_init(stack.a, ft_check_same(&av[i]));
//	printf("before sort\n");
//	ft_print_node(stack.a);
	stack.a->cnt = ft_lstcnt(stack.a);
	stack.b->cnt = ft_lstcnt(stack.b);
//	printf("after sort\n");
	ft_quick_sort_init(&stack, 0, ac - 1);
	//printf("stack a\n");
//	ft_print_node(stack.a);
	//printf("stack b\n");
//	ft_print_node(stack.b);
	return (0);
}
