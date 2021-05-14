/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:01:31 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/14 13:33:38 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	if (stack->a->cnt > 1)
	{
		tmp = stack->a->head;
		stack->a->head = stack->a->tail;
		stack->a->tail = stack->a->tail->prev;
		if (stack->is_push_swap)
			write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	if (stack->b->cnt > 1)
	{
		tmp = stack->b->head;
		stack->b->head = stack->b->tail;
		stack->b->tail = stack->b->tail->prev;
		if (stack->is_push_swap)
			write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->is_push_swap)
	{
		write(1, "rrr\n", 4);
		stack->is_push_swap = 0;
	}
	ft_rra(stack);
	ft_rrb(stack);
}
