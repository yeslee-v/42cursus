/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:01:31 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/14 13:35:58 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->a->cnt > 1)
	{
		stack->a->head = stack->a->head->next;
		stack->a->tail = stack->a->tail->next;
		if (stack->is_push_swap)
			write(1, "ra\n", 3);
	}
}

void	ft_rb(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->b->cnt > 1)
	{
		stack->b->head = stack->b->head->next;
		stack->b->tail = stack->b->tail->next;
		if (stack->is_push_swap)
			write(1, "rb\n", 3);
	}
}

void	ft_rr(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->is_push_swap)
	{
		write(1, "rr\n", 3);
		stack->is_push_swap = 0;
	}
	ft_ra(stack);
	ft_rb(stack);
}
