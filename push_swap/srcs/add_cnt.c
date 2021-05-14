/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:05:04 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/14 18:05:47 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_count_element(t_lst *stack)
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

void	ft_add_p(t_lst *lst, int value)
{
	t_node *new;
	t_node *tmp;

	new = NULL;
	new = ft_get_node(new);
	new->data = value;
	if (!(lst->head) && !(lst->tail))
	{
		new->next = new;
		new->prev = new;
		lst->head = new;
		lst->tail = new;
	}
	else
	{
		tmp = lst->head;
		tmp->prev = new;
		new->prev = lst->tail;
		lst->head = new;
		lst->head->next = tmp;
		lst->tail->next = lst->head;
	}
}
