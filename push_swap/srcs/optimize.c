/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:09:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/03 11:14:05 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_lst *stack)
{
	t_node *x;
	t_node *y;
	t_node *z;

	x = stack->head;
	y = stack->head->next;
	z = stack->head->next->next;
	if ((x->data < z->data) && (y->data < z->data))
	{
		if (x->data < y->data)
			write(1, "OK\n", 3);
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
	ft_print_node(stack);
}

void	ft_sort_two(t_lst *stack)
{
	int	tmp;

	if (stack->head->next->data < stack->head->data)
	{
		tmp = stack->head->data;
		stack->head->data = stack->head->next->data;
		stack->head->next->data = tmp;
	}
	ft_print_node(stack);
}
