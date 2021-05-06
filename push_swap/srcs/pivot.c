/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:31:20 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/06 14:42:35 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(int *arr, int max)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < (max - 1))
	{
		j = i + 1;
		while (j < max)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*ft_intdup(t_lst *stack)
{
	int	i;
	int	*new;
	t_node	*node;

	i = -1;
	if (!(new = malloc(sizeof(int) * stack->cnt)))
		return (0);
	node = stack->head;
	while (++i < stack->cnt)
	{
		new[i] = node->data;
		node = node->next;
	}
	return (new);
}

int	*ft_set_idx(t_lst *lst)
{
	int	*arr;

	arr = ft_intdup(lst);
	ft_bubble_sort(arr, lst->cnt);
	return (arr);
}

void	ft_quick_sort_init(t_stack *stack, int min, int max)  // idx
{
	stack->arr = ft_set_idx(stack->a);
	if (3 < stack->a->cnt)
		ft_a_to_b(stack, min, max);
	else
	{
		if (stack->a->cnt == 2)
			ft_sort_two(stack->a);
		else if (stack->a->cnt == 3)
			ft_sort_three(stack->a);
	}
}
