/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:14:17 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/14 20:04:11 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_node_init(t_lst *lst, int value)
{
	t_node	*node;

	node = NULL;
	node = ft_get_node(node);
	node->data = value;
	if (!(lst->head) && !(lst->tail))
	{
		node->next = node;
		node->prev = node;
		lst->head = node;
		lst->tail = node;
	}
	else
	{
		lst->tail->next = node;
		node->prev = lst->tail;
		lst->tail = node;
		lst->head->prev = lst->tail;
		lst->tail->next = lst->head;
	}
}

t_node		*ft_get_node(t_node *node)
{
	if (!(node = malloc(sizeof(t_node))))
		return (NULL);
	node->data = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_lst		*ft_init_list(t_lst *lst)
{
	if (!(lst = malloc(sizeof(t_lst))))
		return (NULL);
	lst->head = NULL;
	lst->tail = NULL;
	lst->cnt = 0;
	return (lst);
}

void		ft_init_val(t_val *val)
{
	val->piv1 = 0;
	val->piv2 = 0;
}
