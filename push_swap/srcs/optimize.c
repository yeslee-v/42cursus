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
	if (ft_lstcnt(stack->a) == 3)
	{
		// printf("rev_sort_3\n");
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
		ft_pa(stack);
		ft_pa(stack);
		ft_pa(stack);
	}
	else // 정렬해야하는 3개 외에 다른 인자가 있는 경우
	{
		// printf("rev_sort_3 + a\n");
		if ((x->data > z->data) && (y->data > z->data))
		{
			if (x->data > y->data) // 3 2 1
				return ;
			else // 2 3 1
			{
				ft_rb(stack);
				ft_pa(stack);
				ft_rrb(stack);
				ft_pa(stack);
				ft_pa(stack);
			}
		}
		else if ((x->data > y->data) && (z->data > y->data))
		{
			if (x->data > z->data) // 3 1 2
			{
				ft_pa(stack);
				ft_rb(stack);
				ft_pa(stack);
				ft_rrb(stack);
				ft_pa(stack);
			}
			else // 2 1 3
			{
				ft_pa(stack);
				ft_pa(stack);
				ft_ra(stack);
				ft_pa(stack);
				ft_sa(stack);
				ft_rra(stack);
			}
		}
		else
		{
			if (y->data > z->data) // 1 3 2
			{
				ft_ra(stack);
				ft_pa(stack);
				ft_pa(stack);
				ft_rrb(stack);
				ft_pa(stack);
			}
			else // 1 2 3
			{
				ft_pa(stack);
				ft_rb(stack);
				ft_sb(stack);
				ft_pa(stack);
				ft_pa(stack);
				ft_rra(stack);
			}
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
	if (ft_lstcnt(stack->a) == 3)
	{
		// printf("sort_3\n");
		// 		ft_print_node(stack->a);
		// ft_print_node(stack->b);
		// 		printf("maybe error..?\n");
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
	else // 정렬해야하는 3개 외에 다른 인자가 있는 경우
	{
		// printf("sort_3 + a\n");
		if ((x->data < z->data) && (y->data < z->data))
		{
			if (x->data < y->data) // 1 2 3
				return ;
			else // 2 1 3
				ft_sa(stack);
		}
		else if ((x->data < y->data) && (z->data < y->data))
		{
			if (x->data < z->data) // 1 3 2
			{
				ft_ra(stack);
				ft_sa(stack);
				ft_rra(stack);
			}
			else // 2 3 1
			{
				ft_pb(stack);
				ft_sa(stack);
				ft_ra(stack);
				ft_pa(stack);
				ft_rra(stack);
			}
		}
		else
		{
			if (y->data < z->data) // 3 1 2
			{
				ft_pb(stack);
				ft_ra(stack);
				ft_pa(stack);
				ft_sa(stack);			
				ft_rra(stack);
			}
			else // 3 2 1
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
	}
	
}

void	ft_sort_two(t_stack *stack)
{
	// printf("sort_2\n");
	if (stack->a->head->next->data < stack->a->head->data)
		ft_sa(stack);
					// ft_print_node(stack->a);
		// ft_print_node(stack->b);
	// printf("*************\n");
}

void	ft_reverse_sort_two(t_stack *stack)
{
	// printf("r_sort_2\n");
	if (stack->b->head->data < stack->b->head->next->data)
		ft_sb(stack);
	ft_pa(stack);
	ft_pa(stack);
		// ft_print_node(stack->a);
		// ft_print_node(stack->b);
		// printf("------+++++++++++");
}