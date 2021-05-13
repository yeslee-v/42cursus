/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:21:43 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/13 22:28:21 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_from_top(t_stack *stack, int	max)
{
	int		top_cnt;
	t_node	*tmp;

	top_cnt = 0;
	tmp = stack->b->head;
	while (tmp)
	{
		if (tmp->data == max)
			return (top_cnt);
		top_cnt++;
		tmp = tmp->next;
		if (tmp == stack->b->head)
			break ;
	}
	return (top_cnt);
}

int		ft_from_bottom(t_stack *stack, int max)
{
	int		bot_cnt;
	t_node	*tmp;

	bot_cnt = 0;
	tmp = stack->b->tail;
	while (tmp)
	{
		if (tmp->data == max)
			return (bot_cnt);
		bot_cnt++;
		tmp = tmp->prev;
		if (tmp == stack->b->tail)
			break ;
	}
	return (bot_cnt);
}

void	ft_find_max(t_stack *stack, int max)
{
	int	top_cnt;
	int	bot_cnt;

	top_cnt = ft_from_top(stack, max);
	bot_cnt = ft_from_bottom(stack, max);
	if (top_cnt == 0)
	{
		ft_pa(stack);
		return ;
	}
	if (bot_cnt == 0)
	{
		ft_rrb(stack);
		ft_pa(stack);
		return ;
	}
	if (top_cnt <= bot_cnt)
	{
		while (top_cnt)
		{
			ft_rb(stack);
			top_cnt--;
		}
	}
	else if (bot_cnt < top_cnt)
	{
		while (bot_cnt)
		{
			ft_rrb(stack);
			bot_cnt--;
		}
		ft_rrb(stack);
	}
	ft_pa(stack);
}

void	ft_b_to_a(t_stack *stack, int max)
{
	ft_find_max(stack, max);
}

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
	else if (200 <= size)
	{
		stack->val.piv1 = max - (size / 9) * 7;
		stack->val.piv2 = max - (size / 9) * 8;
	}
	else if (100 <= size)
	{
		stack->val.piv1 = max - (size / 8) * 6;
		stack->val.piv2 = max - (size / 8) * 7;
	}
	else if (size <= 30)
	{
		stack->val.piv1 = max - (size / 3);
		stack->val.piv2 = max - (size / 3) * 2;
	}
	else
	{
		stack->val.piv1 = max - (size / 3) * 1;
		stack->val.piv2 = max - (size / 3) * 2;
	}
}

void	ft_a_to_b(t_stack *stack, int size)
{
	if (size <= 3)
		return (ft_optimize(stack, size));
	ft_set_pivot(stack, size);
	while (size > 0)
	{
		if (stack->val.piv1 <= stack->a->head->data)
			ft_ra(stack);
		else
		{
			ft_pb(stack);
			if (ft_lstcnt(stack->b) >= 2 && stack->val.piv2 >= stack->b->head->data)
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
