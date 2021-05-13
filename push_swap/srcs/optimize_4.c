/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:42:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/13 21:06:37 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_num(t_stack *stack, int num)
{
	int		i;
	int		node_cnt;
	t_node *tmp;

	i = 0;
	tmp = stack->a->head;
	while (++i <= ft_lstcnt(stack->a))
	{
		if (tmp->data == num)
		{
			node_cnt = i;
			return (node_cnt);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_sort_four(t_stack *stack)
{
	int	cnt;
	int	first;
	int	idx;

	cnt = 0;
	first = ft_set_min(stack->a);
	idx = ft_find_num(stack, first);
	while (++cnt < 5)
	{
		if (cnt == idx)
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
	ft_pa(stack);
}
