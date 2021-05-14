/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:21:43 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/14 17:55:21 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimize(t_stack *stack, int i)
{
	if (ft_is_sorted(stack->a))
		return ;
	else if	(i == 2)
		ft_sort_two(stack);
	else if (i == 3)
		ft_sort_three(stack);
	else if (i == 4)
		ft_sort_four(stack);
	else if (i == 5)
		ft_sort_five(stack);
	return ;
}
void	ft_set_pivot_under_200(t_stack *stack, int size, int max)
{
	if (200 <= size)
	{
		stack->val.piv1 = max - (size / 9) * 7;
		stack->val.piv2 = max - (size / 9) * 8;
	}
	else if (100 <= size)
	{
		stack->val.piv1 = max - (size / 8) * 6;
		stack->val.piv2 = max - (size / 8) * 7;
	}
	else
	{
		stack->val.piv1 = max - (size / 3) * 1;
		stack->val.piv2 = max - (size / 3) * 2;
	}
}

void	ft_set_pivot(t_stack *stack, int size)
{
	int max;

	max = ft_set_max(stack->a);
	if (size >= 500)
	{
		stack->val.piv1 = max - (size / 12) * 10;
		stack->val.piv2 = max - (size / 12) * 11;
	}
	else if (400 <= size)
	{
		stack->val.piv1 = max - (size / 11) * 9;
		stack->val.piv2 = max - (size / 11) * 10;
	}
	else if (300 <= size)
	{
		stack->val.piv1 = max - (size / 10) * 8;
		stack->val.piv2 = max - (size / 10) * 9;
	}
	else if (size < 300)
		ft_set_pivot_under_200(stack, size, max);
}

void	ft_a_to_b(t_stack *stack, int size)
{
	if (size < 6)
		return (ft_optimize(stack, size));
	ft_set_pivot(stack, size);
	while (size > 0)
	{
		if (stack->val.piv1 <= stack->a->head->data)
			ft_ra(stack);
		else
		{
			ft_pb(stack);
			if (ft_lstcnt(stack->b) >= 2 &&
					(stack->val.piv2 >= stack->b->head->data))
			{
				if (stack->val.piv1 <= stack->a->head->data)
				{
					ft_rr(stack);
					stack->is_push_swap = 1;
					size--;
				}
				else
					ft_rb(stack);
			}
		}
		size--;
	}
	ft_a_to_b(stack, ft_lstcnt(stack->a));
}
