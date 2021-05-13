/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:31:20 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/13 22:32:45 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_max(t_lst *lst)
{
	int		max;
	t_node	*tmp;

	tmp = lst->head;
	max = lst->head->data;
	while (tmp)
	{
		if (max < tmp->data)
			max = tmp->data;
		tmp = tmp->next;
		if (tmp == lst->head)
			break ;
	}
	return (max);
}

int	ft_set_min(t_lst *lst)
{
	int		min;
	t_node	*tmp;

	tmp = lst->head;
	min = lst->head->data;
	while (tmp)
	{
		if (min > tmp->data)
			min = tmp->data;
		tmp = tmp->next;
		if (tmp == lst->head)
			break ;
	}
	return (min);
}

void	ft_quick_sort_init(t_stack *stack)
{
	stack->is_push_swap = 1;
		ft_a_to_b(stack, ft_lstcnt(stack->a));
		while (ft_lstcnt(stack->b) > 0)
			ft_b_to_a(stack, ft_set_max(stack->b));
}
