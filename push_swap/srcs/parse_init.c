/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:09:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/05 22:50:39 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_count_element(t_lst *stack)	// min,mid,max로 몇 개 보냈는
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = stack->head;
	while (node)
	{
		cnt++;
		node = node->next;
		if (node == stack->head)
			break ;
	}
	return (cnt);
}

void	ft_a_to_b(t_stack *stack, int min, int max)	// idx
{
	int	i;
	int	piv1;
	int	piv2;

	i = max - min + 1;
	if (i == 3 || i == 2)
		return ;
	piv1 = (max - min) / 3;
	piv2 = (2 * (max - min)) / 3;
	while (stack->a && (--i > 0))
	{
		printf("i:%d\n", i);
		if (stack->a->head->data < stack->arr[piv1])
		{
			printf("min:%d\n", stack->a->head->data);
			ft_pb(stack->a, stack->b);
		}
		else if ((stack->arr[piv1] <= stack->a->head->data) && (stack->a->head->data < stack->arr[piv2]))
		{
			printf("mid:%d\n", stack->a->head->data);
			ft_pb(stack->a, stack->b);
			ft_rb(stack->b);
		}
		 else
		 {
			printf("max:%d\n", stack->a->head->data);
			ft_ra(stack->a);
		 }
	}
	ft_a_to_b(stack, piv2, max); //max
//	ft_b_to_a(stack, piv1, piv2); //mid
//	ft_b_to_a(stack, min, piv1); //min
	ft_print_node(stack->a);
	ft_print_node(stack->b);
}

/*void		ft_b_to_a(t_lst *a, t_lst *b) // 스택의 갯수를 구하는
{
	t_node *node;
}*/
