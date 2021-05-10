/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:42:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/09 21:56:58 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_num(t_stack *stack, int num)
{
	int		i;
	int		node_cnt;
	t_node *tmp;

	i = 0;
	tmp = stack->a->head;
	while (++i <= ft_lstcnt(stack->a))
	{
		if (tmp->data == num)
		{
			node_cnt = i;
			return (node_cnt);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_sort_five(t_stack *stack)
{
	int	first;
	int	second;
	int	cnt = 0;

	first = stack->arr[0];
	second = stack->arr[1];
	int	first_idx = ft_find_num(stack, first);
	// printf(">>>>>>>first: %d second: %d\n", first_idx, second_idx);
	while (++cnt < 6) // seprate first second while
	{
	/*	printf("\n++++++++++[before]+++++++++++\n");
		printf("[stack a]\n");
		ft_print_node(stack->a);
		printf("[stack b]\n");
		ft_print_node(stack->b);
		printf("cnt:%d\n", cnt);*/
		if (cnt == first_idx)
		{
			printf("****it is first*****\n");
			if (cnt < 3)
			{
				printf("1: %d %d\n", cnt, stack->a->head->data);
				int reset = cnt;
				while (--reset)
					ft_ra(stack);
			}
			else if (3 <= cnt)
			{
				printf("2: %d %d\n", cnt, stack->a->head->data);
				int reset = cnt - ft_lstcnt(stack->a) + 1;
				printf("reset:%d\n", reset);
				while (--reset)
					ft_rra(stack);
			}
			printf("3: %d %d\n", cnt, stack->a->head->data);
			ft_pb(stack);
			//printf("cnt:%d\n", cnt);
		}
	}
	int	second_idx= ft_find_num(stack, second);
	while (++cnt < 6) // seprate first second while
	{
		if (cnt == second_idx)
		{
			printf("****it is second*****\n");
			if (cnt < 2)
			{
			int reset = cnt;
				printf("4: %d %d\n", cnt, stack->a->head->data);
				while (--reset)
					ft_ra(stack);
			}
			else if (2 <= cnt)
			{
				int reset = ft_lstcnt(stack->a) - cnt + 1;
				printf("5: %d %d %d\n", cnt, stack->a->head->data, reset);
				while (--reset)
					ft_ra(stack);
			}
			printf("6: %d %d\n", cnt, stack->a->head->data);
			ft_pb(stack);
		}
		printf("\n++++++++++[after]+++++++++++\n");
		printf("[stack a]\n");
		ft_print_node(stack->a);
		printf("[stack b]\n");
		ft_print_node(stack->b);
	}
	ft_sort_three(stack);
	if (stack->b->head->data < stack->b->head->next->data)
		ft_sb(stack);
	ft_pa(stack);
	ft_pa(stack);
	/*	printf("\n++++++++++[after]+++++++++++\n");
		printf("[stack a]\n");
		ft_print_node(stack->a);
		printf("[stack b]\n");
		ft_print_node(stack->b);*/
}
