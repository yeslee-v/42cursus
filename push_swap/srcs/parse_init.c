/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:09:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/30 16:51:54 by yeslee           ###   ########.fr       */
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

void	ft_quick_sort(t_lst *stack, int piv1, int piv2)
{
	t_node	*tmp;

	tmp = stack->head;
	printf("piv1:%d piv2:%d\n", piv1, piv2);
	printf("==============\n");
	while (tmp)
	{
		if (tmp->data < piv1)
			printf("min: %d\n", tmp->data);
		else if ((piv1 <= tmp->data) && (tmp->data < piv2))
			printf("mid: %d\n", tmp->data);
		else
			printf("max: %d\n", tmp->data);
		tmp = tmp->next;
		if (tmp == stack->head)
			break ;
	}
	ft_print_node(stack);
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
	int		piv1;
	int		piv2;
	t_node	*tmp;
	t_lst	*have_to_set;

	i = 0;
	have_to_set = ft_lstdup(stack);
	ft_bubble_sort(stack);
	tmp = stack->tail;
	while (++i <= stack->cnt)
	{
		if (i == (stack->cnt / 3))
			piv1 = tmp->data;
		else if (i == ((2 * stack->cnt) / 3))
			piv2 = tmp->data;
		tmp = tmp->prev;
		if (tmp == stack->tail)
			break ;
	}
	if (piv2 < piv1)
	{
		i = piv1;
		piv1 = piv2;
		piv2 = i;
	}
	ft_quick_sort(have_to_set, piv1, piv2);
}
