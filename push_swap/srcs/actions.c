/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:47:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/28 22:01:28 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_lst *lst)
{
	int	tmp;

	tmp = lst->head->data;
	lst->head->data = lst->head->next->data;
	lst->head->next->data = tmp;
}

void	ft_r(t_lst *lst)
{
	t_node	*tmp;

	tmp = lst->head;
	lst->head = lst->head->next;
	lst->head->prev = tmp;
	lst->tail = tmp;
	lst->tail->next = lst->head;
}

void	ft_rr(t_lst *lst)
{
	t_node	*tmp;

	tmp = lst->head;
	lst->head = lst->tail;
	lst->tail = lst->tail->prev;
	lst->head->next = tmp;
}

void	ft_del(t_lst *t)
{
	t_node *tmp;

	tmp = t->head;
	t->head = tmp->next;
	t->head->prev = tmp->prev;
	t->tail->next = t->head;
	t->cnt--;
	free(tmp);
	tmp = NULL;
}

int	ft_p(t_lst *a, t_lst *b)
{
	ft_node_init(b, a->head->data);
	ft_del(a);
	return (1);
}
