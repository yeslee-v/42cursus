/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:14:17 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/08 11:35:33 by yeslee           ###   ########.fr       */
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

void	ft_node_init(t_lst *lst, int value)
{
	t_node *new;

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
		lst->tail->next = new;
		new->prev = lst->tail;
		lst->tail = new;
		lst->head->prev = lst->tail;
		lst->tail->next = lst->head;
	}
	lst->cnt++;
}

t_node	*ft_get_node(t_node *new)
{
	if (!(new = malloc(sizeof(t_node))))
		return (NULL);
	new->data = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_lst	*ft_init_list(t_lst *lst)
{
	if (!(lst = malloc(sizeof(t_lst))))
		return (NULL);
	lst->head = NULL;
	lst->tail = NULL;
	lst->cnt = 0;
	return (lst);
}
