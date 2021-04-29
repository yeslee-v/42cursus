/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:09:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/29 19:24:17 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(t_lst *stack)
{
	int	i;
	int j;
	int tmp;
	t_node 	*base;
	t_node	*value;

	i = stack->cnt + 1;
	base = stack->head;
	while (--i)
	{
		j = i;
		value = base->next;
		while (--j)
		{
			if (value->data < base->data)
			{
				tmp = base->data;
				base->data = value->data;
				value->data = tmp;
			}
			value = value->next;
		}
		base = base->next;
	}
}

void	ft_quick_sort(t_lst *stack, t_node *piv1, t_node *piv2)
{
	ft_print_node(stack);
	printf("piv1:piv2 = %d:%d\n", piv1->data, piv2->data);
}

t_lst	*ft_lstdup(t_lst *stack)
{
	int		i;
	t_lst	*new;
	t_node	*node;
	
	i = -1;
	new = NULL;
	new = ft_init_list(new);
	node = stack->head;
	while (++i < stack->cnt)
	{
		ft_node_init(new, node->data);
		node = node->next;
	}
	return (new);
}



void	ft_set_pivot(t_lst *stack)
{
	int		i;
	t_node	*piv1;
	t_node	*piv2;
	t_node	*tmp;
	t_lst	*have_to_set;

	i = 0;
	have_to_set = ft_lstdup(stack);
	ft_print_node(have_to_set);
	ft_bubble_sort(stack);
	tmp = stack->tail;
	while (++i <= stack->cnt)
	{
		if (i == (stack->cnt / 3))
			piv1 = tmp;
		else if (i == ((2 * stack->cnt) / 3))
			piv2 = tmp;
		tmp = tmp->prev;
		if (tmp == stack->tail)
			break ;
	}
	ft_quick_sort(have_to_set, piv1, piv2);
}
