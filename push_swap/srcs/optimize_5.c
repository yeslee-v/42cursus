/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:42:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/14 15:38:47 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_pb_first(t_stack *stack, int first)
{
	int		cnt;
	int		reset;
	int		first_idx;

	cnt = 0;
	first_idx = ft_find_num(stack, first);
	while (++cnt < 6)
	{
		if (cnt == first_idx)
		{
			if (cnt < 3)
			{
				reset = cnt;
				while (--reset)
					ft_ra(stack);
			}
			else if (3 <= cnt)
			{
				reset = ft_lstcnt(stack->a) - cnt + 2;
				while (--reset)
					ft_rra(stack);
			}
			ft_pb(stack);
		}
	}
}

static void	ft_pb_second(t_stack *stack, int second)
{
	int		cnt;
	int		reset;
	int		second_idx;

	cnt = 0;
	second_idx = ft_find_num(stack, second);
	while (++cnt < 5)
	{
		if (cnt == second_idx)
		{
			if (cnt <= 2)
			{
				reset = cnt;
				while (--reset)
					ft_ra(stack);
			}
			else if (2 < cnt)
			{
				reset = ft_lstcnt(stack->a) - cnt + 2;
				while (--reset)
					ft_rra(stack);
			}
			ft_pb(stack);
		}
	}
}

void		ft_sort_five(t_stack *stack)
{
	int		first;
	int		second;

	first = ft_set_min(stack->a);
	ft_pb_first(stack, first);
	second = ft_set_min(stack->a);
	ft_pb_second(stack, second);
	ft_sort_three(stack);
	if (stack->b->head->data < stack->b->head->next->data)
		ft_sb(stack);
	ft_pa(stack);
	ft_pa(stack);
}
