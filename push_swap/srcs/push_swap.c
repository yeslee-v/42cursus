/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:21:43 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/10 17:40:51 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("[ Printing b_to_a ]\n");
	int	i;
	int	piv1;
	int	piv2;
	int	ra_num;
	int	rb_num;
	
	ra_num = 0;
	rb_num = 0;
	i = max - min;
	int cnt = i + 1;
	piv1 = (max - min) / 3 + min;
	piv2 = (2 * (max - min)) / 3 + min;
	printf("[btoa]min %d max %d piv 1 = %d piv 2 = %d\n",min, max, piv1, piv2);
	if (ft_lstcnt(stack->b) < 1 || i < 1)
		return ;
	else if (ft_lstcnt(stack->b) == 1|| i == 1)
	{
		ft_pa(stack);
		return ;
	}
	else if (ft_lstcnt(stack->b) == 2|| i == 2)
	{
		ft_reverse_sort_two(stack);
		return ;
	}
	else if (ft_lstcnt(stack->b) == 3|| i == 3)
	{
		ft_reverse_sort_three(stack);
		return ;
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
				ft_print_node(stack->a);
		ft_print_node(stack->b);
	}
	ft_a_to_b(stack, piv2, max);
	ft_set_rrr(stack, ra_num, rb_num);
	ft_a_to_b(stack, piv1, piv2);
	ft_b_to_a(stack, min, piv1);

}

void	ft_a_to_b_init(t_stack *stack, int min, int max)
{
	printf("[ Printing a_to_b_init ]\n");	
	int	i;
	int	piv1;
	int	piv2;
	int	ra_num;
	int	rb_num;

	ra_num = 0;
	rb_num = 0;
	i = max - min;
	int cnt = i + 1;
	if (i < 2)
		return ;
	else if	(i == 2)
	{
		ft_sort_two(stack);
		return ;
	}
	else if (i == 3)
	{
		ft_sort_three(stack);
		return ;
	}
	piv1 = (max - min) / 3 + min;
	piv2 = (2 * (max - min)) / 3 + min;
	printf("[atob]min %d max %d piv 1 = %d piv 2 = %d\n",min, max, piv1, piv2);
	while (--cnt)
	{
		printf("[%d]\n", stack->a->head->data);
		if (stack->arr[piv2] <= stack->a->head->data) // max
		{
			printf(">>>>>>>>>>>>>>>>max:%d\n", stack->a->head->data);
			ra_num += ft_ra(stack);
		}
		else // mid
		{
		
			ft_pb(stack);

			if (stack->arr[piv1] > stack->b->head->data) // min
			{
				printf(">>>>>>>>>>>>>min:%d\n", stack->b->head->data);
				rb_num += ft_rb(stack);
			}
			else
			{
					printf(">>>>>>>>>>>>>mid:%d\n", stack->b->head->data);
			}
			
		}
		// printf("stack a----------\n");
		// ft_print_node(stack->a);
		// printf("stack b----------\n");
		// ft_print_node(stack->b);
	}
		// printf("after a_to_b_init\n");
		// ft_print_node(stack->a);
		// ft_print_node(stack->b);
	ft_a_to_b(stack, piv2, max);
	ft_b_to_a(stack, piv1, piv2);
	ft_b_to_a(stack, min, piv1);
	printf("after a_to_b\n");
		ft_print_node(stack->a);
		ft_print_node(stack->b);
}

void	ft_a_to_b(t_stack *stack, int min, int max)
{
	printf("[ Printing a_to_b ]\n");	
	int	i;
	int	piv1;
	int	piv2;
	int	ra_num;
	int	rb_num;

	ra_num = 0;
	rb_num = 0;
	i = max - min;
	int cnt = i + 1;
	if (i < 2)
		return ;
	else if	(i == 2)
	{
		ft_sort_two(stack);
		return ;
	}
	else if (i == 3)
	{
		ft_sort_three(stack);
		return ;
	}
	piv1 = (max - min) / 3 + min;
	piv2 = (2 * (max - min)) / 3 + min;
//	printf("[atob]min %d max %d piv 1 = %d piv 2 = %d\n",min, max, piv1, piv2);
	while (--cnt)
	{
		if (stack->arr[piv2] <= stack->a->head->data)
			ra_num += ft_ra(stack);
		else // min
		{
			ft_pb(stack);
			if (stack->arr[piv1] <= stack->b->head->data)
				rb_num += ft_rb(stack);
		}
		// printf("stack a----------\n");
		// ft_print_node(stack->a);
		// printf("stack b----------\n");
		// ft_print_node(stack->b);
	}
	ft_set_rrr(stack, ra_num, rb_num);
	ft_a_to_b(stack, piv2, max);
	ft_b_to_a(stack, piv1, piv2);
	ft_b_to_a(stack, min, piv1);
		// ft_print_node(stack->a);
		// ft_print_node(stack->b);
}
