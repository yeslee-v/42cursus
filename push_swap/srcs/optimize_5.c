/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:42:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/13 21:12:42 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(t_stack *stack)
{
	int	first;
	int	second;
	int	cnt = 0;

	first = ft_set_min(stack->a);
	int	first_idx = ft_find_num(stack, first);
	while (++cnt < 6)
	{
		if (cnt == first_idx)
		{
			if (cnt < 3)
			{
				int reset = cnt;
				while (--reset)
					ft_ra(stack);
			}
			else if (3 <= cnt)
			{
				int reset = ft_lstcnt(stack->a) - cnt + 2;
				while (--reset)
					ft_rra(stack);
			}
			ft_pb(stack);
		}
	}
	second = ft_set_min(stack->a);
	int	second_idx= ft_find_num(stack, second);
	cnt = 0;
	while (++cnt < 5)
	{
		if (cnt == second_idx)
		{
			if (cnt <= 2)
			{
			int reset = cnt;
				while (--reset)
					ft_ra(stack);
			}
			else if (2 < cnt)
			{
				int reset = ft_lstcnt(stack->a) - cnt + 2;
				while (--reset)
					ft_rra(stack);
			}
			ft_pb(stack);
		}
	}
	ft_sort_three(stack);
	if (stack->b->head->data < stack->b->head->next->data)
		ft_sb(stack);
	ft_pa(stack);
	ft_pa(stack);
}
