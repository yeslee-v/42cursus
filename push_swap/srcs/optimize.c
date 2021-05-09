/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:09:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/09 21:57:02 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_sort_three(t_stack *stack)
{
	t_node *x;
	t_node *y;
	t_node *z;

	x = stack->b->head;
	y = stack->b->head->next;
	z = stack->b->head->next->next;
	if ((x->data > z->data) && (y->data > z->data))
	{
		if (x->data > y->data) // 3 2 1
			return ;
		else // 2 3 1
			ft_sb(stack);
	}
	else if ((x->data > y->data) && (z->data > y->data))
	{
		if (x->data > z->data) // 3 1 2
		{
			ft_rrb(stack);
			ft_sb(stack);
		}
		else // 2 1 3
			ft_rrb(stack);
	}
	else
	{
		if (y->data > z->data) // 1 3 2
			ft_rb(stack);
		else // 1 2 3
		{
			ft_rb(stack);
			ft_sb(stack);
		}
	}
}

void	ft_sort_three(t_stack *stack)
{
	t_node *x;
	t_node *y;
	t_node *z;

	x = stack->a->head;
	y = stack->a->head->next;
	z = stack->a->head->next->next;
	if ((x->data < z->data) && (y->data < z->data))
	{
		if (x->data < y->data)
			return ;
		else
			ft_sa(stack);
	}
	else if ((x->data < y->data) && (z->data < y->data))
	{
		if (x->data < z->data)
		{
			ft_sa(stack);
			ft_ra(stack);
		}
		else
			ft_rra(stack);
	}
	else
	{
		if (y->data < z->data)
			ft_ra(stack);
		else
		{
			ft_sa(stack);
			ft_rra(stack);
		}
	}
}

void	ft_sort_two(t_stack *stack)
{
	if (stack->a->head->next->data < stack->a->head->data)
		ft_sa(stack);
}
