/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:35:14 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/14 13:35:22 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	if (stack->a->cnt > 1)
	{
		tmp = stack->a->head->data;
		stack->a->head->data = stack->a->head->next->data;
		stack->a->head->next->data = tmp;
		if (stack->is_push_swap)
			write(1, "sa\n", 3);
	}
}

void	ft_sb(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	if (stack->b->cnt > 1)
	{
		tmp = stack->b->head->data;
		stack->b->head->data = stack->b->head->next->data;
		stack->b->head->next->data = tmp;
		if (stack->is_push_swap)
			write(1, "sb\n", 3);
	}
}

void	ft_ss(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->is_push_swap)
	{
		write(1, "ss\n", 3);
		stack->is_push_swap = 0;
	}
	ft_sa(stack);
	ft_sb(stack);
}
