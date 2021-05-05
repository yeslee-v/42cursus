/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:47:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/05 13:26:00 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_lst *lst)
{
	int	tmp;

	if (lst->cnt > 1)
	{
		tmp = lst->head->data;
		lst->head->data = lst->head->next->data;
		lst->head->next->data = tmp;
	}
}

void	ft_sb(t_lst *lst)
{
	int	tmp;

	if (lst->cnt > 1)
	{
		tmp = lst->head->data;
		lst->head->data = lst->head->next->data;
		lst->head->next->data = tmp;
	}
}

void	ft_ss(t_lst *a, t_lst *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_ra(t_lst *lst)
{
	t_node	*tmp;

	if (lst->cnt > 1)
	{
		tmp = lst->head;
		lst->head = lst->head->next;
		lst->head->prev = tmp;
		lst->tail = tmp;
		lst->tail->next = lst->head;
	}
}

void	ft_rb(t_lst *lst)
{
	t_node	*tmp;

	if (lst->cnt > 1)
	{
		tmp = lst->head;
		lst->head = lst->head->next;
		lst->head->prev = tmp;
		lst->tail = tmp;
		lst->tail->next = lst->head;
	}
}

void	ft_rr(t_lst *a, t_lst *b)
{
	ft_ra(a);
	ft_rb(b);
}

void	ft_rra(t_lst *lst)
{
	t_node	*tmp;
	
	if (lst->cnt > 1)
	{
		tmp = lst->head;
		lst->head = lst->tail;
		lst->tail = lst->tail->prev;
		lst->head->next = tmp;
	}
}

void	ft_rrb(t_lst *lst)
{
	t_node	*tmp;

	if (lst->cnt > 1)
	{
		tmp = lst->head;
		lst->head = lst->tail;
		lst->tail = lst->tail->prev;
		lst->head->next = tmp;
	}
}

void	ft_rrr(t_lst *a, t_lst *b)
{
	ft_rra(a);
	ft_rrb(b);
}

void	ft_del(t_lst *t)
{
	t_node *tmp;

	tmp = t->head;
	t->head = tmp->next;
	t->head->prev = tmp->prev;
	t->tail->next = t->head;
	t->cnt--;
	//free(tmp);
	tmp = NULL;
}

int	ft_pa(t_lst *a, t_lst *b)
{
	if (b->cnt > 1)
	{
		ft_node_init(b, a->head->data);
		ft_del(a);
		return (1);
	}
	return (0);
}

int	ft_pb(t_lst *b, t_lst *a)
{
	if (b->cnt > 1)
	{
		ft_node_init(a, b->head->data);
		ft_del(b);
		return (1);
	}
	return (0);
}
