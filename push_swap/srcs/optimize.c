/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:09:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/30 22:02:50 by yeslee           ###   ########.fr       */
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
			printf("OK\n");
		else
			ft_s(stack);
	}
	else if ((x->data < y->data) && (z->data < y->data))
	{
		if (x->data < z->data)
		{
			ft_s(stack);
			ft_r(stack);
		}
		else
			ft_rr(stack);
	}
	else
	{
		if (y->data < z->data)
			ft_r(stack);
		else
		{
			ft_s(stack);
			ft_rr(stack);
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
