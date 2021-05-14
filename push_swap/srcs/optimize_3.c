/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:03:05 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/14 15:16:08 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_smallest_z(t_stack *stack, t_node *x, t_node *y, t_node *z)
{
	if ((x->data < y->data) && (z->data < y->data))
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

static void		ft_real_three(t_stack *stack, t_node *x, t_node *y, t_node *z)
{
	if ((x->data < z->data) && (y->data < z->data))
	{
		if (x->data < y->data)
			return ;
		else
			ft_sa(stack);
	}
	else
		ft_smallest_z(stack, x, y, z);
}

static void		ft_biggest_y(t_stack *stack, t_node *x, t_node *z)
{
	if (x->data < z->data)
	{
		ft_ra(stack);
		ft_sa(stack);
		ft_rra(stack);
	}
	else
	{
		ft_pb(stack);
		ft_sa(stack);
		ft_ra(stack);
		ft_pa(stack);
		ft_rra(stack);
	}
}

static	void	ft_biggest_x(t_stack *stack, t_node *y, t_node *z)
{
	if (y->data < z->data)
	{
		ft_pb(stack);
		ft_ra(stack);
		ft_pa(stack);
		ft_sa(stack);
		ft_rra(stack);
	}
	else
	{
		ft_ra(stack);
		ft_sa(stack);
		ft_pb(stack);
		ft_pb(stack);
		ft_rra(stack);
		ft_pa(stack);
		ft_pa(stack);
	}
}

void			ft_sort_three(t_stack *stack)
{
	t_node	*x;
	t_node	*y;
	t_node	*z;

	x = stack->a->head;
	y = stack->a->head->next;
	z = stack->a->head->next->next;
	if (ft_lstcnt(stack->a) == 3)
		ft_real_three(stack, x, y, z);
	else
	{
		if ((x->data < z->data) && (y->data < z->data))
		{
			if (x->data < y->data)
				return ;
			else
				ft_sa(stack);
		}
		else if ((x->data < y->data) && (z->data < y->data))
			ft_biggest_y(stack, x, z);
		else
			ft_biggest_x(stack, y, z);
	}
}
