/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:09:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/03 13:40:44 by yeslee           ###   ########.fr       */
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

// void		ft_b_to_a(t_lst *a, t_lst *b) // 스택의 갯수를 구하는
// {
// 	t_node *node;
// }

int		ft_count_element(t_lst *stack)	// min,mid,max로 몇 개 보냈는
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = stack->head;
	while (node)
	{
		cnt++;
		node = node->next;
		if (node == stack->head)
			break ;
	}
	return (cnt);
}

void	ft_quick_sort(t_lst *a, t_lst *b, int piv1, int piv2)
{
	int		i;

	i = a->cnt + 1;
	printf("piv1:%d piv2:%d i: %d\n", piv1, piv2, i);
	while (a && (--i > 0))
	{
		if (a->head->data < piv1)
		{
			ft_pa(a, b);
			ft_rrb(b);
		}
		else if ((piv1 <= a->head->data) && (a->head->data < piv2))
		{
			ft_pa(a, b);
		}
		 else
		 {
			ft_ra(a);
		 }
	}
	int res = ft_count_element(a);
	// if (
	ft_set_pivot(a, b);
	printf("res:%d | in stack A:%d\n", res, (res / 3));
	ft_print_node(a);
	ft_print_node(b);
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

void	ft_set_pivot(t_lst *a, t_lst *b)
{
	int		i;
	int		piv1;
	int		piv2;
	t_node	*tmp;
	t_lst	*stack_piv;

	i = 0;
	stack_piv = ft_lstdup(a);
	ft_bubble_sort(stack_piv);
	tmp = stack_piv->tail;
	if (3 < stack_piv->cnt)
	{
		while (++i <= stack_piv->cnt)
		{
			if (i == (stack_piv->cnt / 3))
				piv1 = tmp->data;
			else if (i == ((2 * stack_piv->cnt) / 3))
				piv2 = tmp->data;
			tmp = tmp->prev;
			if (tmp == stack_piv->tail)
				break ;
		}
		if (piv2 < piv1)
		{
			i = piv1;
			piv1 = piv2;
			piv2 = i;
		}
		ft_quick_sort(a, b, piv1, piv2);
	}
	else
	{
		if (a->cnt == 2)
			ft_sort_two(a);
		else if (a->cnt == 3)
			ft_sort_three(a);
	}
}
