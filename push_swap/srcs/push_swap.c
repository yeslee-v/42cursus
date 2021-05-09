/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:21:43 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/09 19:27:19 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_rr(t_stack *stack, int ra_num, int rb_num)
{
	if (ra_num == rb_num)
	{
		while (ra_num)
		{
			ft_rr(stack);
			stack->is_push_swap = 1;
			ra_num--;
		}
	}
	else
	{
		if (ra_num < rb_num)
		{
			while (ra_num)
			{
				ft_rr(stack);
				ra_num--;
			}
			stack->is_push_swap = 1;
			ft_rb(stack);
		}
		else
		{
			while (rb_num)
			{
				ft_rr(stack);
				rb_num--;
			}
			stack->is_push_swap = 1;
			ft_ra(stack);
		}
	}
}

void	ft_set_rrr(t_stack *stack, int ra_num, int rb_num)
{
	if (ra_num == rb_num)
	{
		while (ra_num)
		{
			ft_rrr(stack);
			stack->is_push_swap = 1;
			ra_num--;
		}
	}
	else
	{
		if (ra_num < rb_num)
		{
			while (ra_num)
			{
				ft_rrr(stack);
				ra_num--;
			}
			stack->is_push_swap = 1;
			ft_rrb(stack);
		}
		else
		{
			while (rb_num)
			{
				ft_rrr(stack);
				rb_num--;
			}
			stack->is_push_swap = 1;
			ft_rra(stack);
		}
	}
}

void	ft_b_to_a(t_stack *stack, int min, int max)
{
	int	i;
	int	piv1;
	int	piv2;
	int	ra_num;
	int	rb_num;
	
	ra_num = 0;
	rb_num = 0;
	i = ft_lstcnt(stack->b);
	int cnt = i + 1;
	piv1 = ((double)max - (double)min) / 3 + min;
	piv2 = (2 * ((double)max - (double)min)) / 3 + min;
//	printf("[btoa]min %d max %d piv 1 = %d piv 2 = %d\n",min, max, piv1, piv2);
	if (!(stack->b->cnt) || i < 1)
		return ;
	else if (stack->b->cnt == 1)
	{
		ft_pa(stack);
		return ;
	}
	else if (stack->b->cnt == 2)
	{
		if (stack->b->head->data < stack->b->head->next->data)
			ft_sb(stack);
		ft_pa(stack);
		ft_pa(stack);
		return ;
	}
	else if (stack->b->cnt == 3)
	{
		ft_reverse_sort_three(stack);
		ft_pa(stack);
		ft_pa(stack);
		ft_pa(stack);
		return ;
	//	ft_print_node(stack->a);
	//	ft_print_node(stack->b);
	}
	else
	{
		while (--cnt)
		{
			if (stack->b->head->data < stack->arr[piv1])
				rb_num += ft_rb(stack);
			else
			{
				ft_pa(stack);
				if (stack->b->head->data < stack->arr[piv2])
					ra_num += ft_ra(stack);
			}
		}
	}
	ft_a_to_b(stack, piv2, max);
	ft_set_rrr(stack, ra_num, rb_num);
	ft_a_to_b(stack, piv1, piv2);
	ft_b_to_a(stack, min, piv1);
}

void	ft_a_to_b(t_stack *stack, int min, int max)
{
//	printf("[ Printing a_to_b ]\n");	
	int	i;
	int	piv1;
	int	piv2;
	int	ra_num;
	int	rb_num;

	ra_num = 0;
	rb_num = 0;
	i = ft_lstcnt(stack->a);
	int cnt = i + 1;
	if (i < 2)
		return ;
	else if	(i == 2)
		return (ft_sort_two(stack));
	else if (i == 3)
		return (ft_sort_three(stack));
	else if (i == 5)
		return (ft_sort_five(stack));
	piv1 = ((double)max - (double)min) / 3 + min;
	piv2 = (2 * ((double)max - (double)min)) / 3 + min;
//	printf("[atob]min %d max %d piv 1 = %d piv 2 = %d\n",min, max, piv1, piv2);
	while (--cnt)
	{
		if (stack->arr[piv2] <= stack->a->head->data)
			ra_num += ft_ra(stack);
		else // min
		{
			ft_pb(stack);
			if (stack->arr[piv1] <= stack->a->head->data)
				rb_num += ft_rb(stack);
		}
	//	printf("stack a----------\n");
	//	ft_print_node(stack->a);
	//	printf("stack b----------\n");
	//	ft_print_node(stack->b);
	}
	ft_set_rrr(stack, ra_num, rb_num);
	ft_a_to_b(stack, piv2, max);
	ft_b_to_a(stack, piv1, piv2);
	ft_b_to_a(stack, min, piv1);
	//	ft_print_node(stack->a);
	//	ft_print_node(stack->b);
}
