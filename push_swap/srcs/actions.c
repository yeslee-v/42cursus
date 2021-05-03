/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:47:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/03 11:16:10 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_lst *lst)
{
	int	tmp;

	tmp = lst->head->data;
	lst->head->data = lst->head->next->data;
	lst->head->next->data = tmp;
	lst->res++;
	write(1, "sa\n", 3);
}

void	ft_sb(t_lst *lst)
{
	int	tmp;

	tmp = lst->head->data;
	lst->head->data = lst->head->next->data;
	lst->head->next->data = tmp;
	lst->res++;
	write(1, "sb\n", 3);
}

void	ft_ra(t_lst *lst)
{
	t_node	*tmp;

//	if (lst->cnt > 1)
//	{
		tmp = lst->head;
		lst->head = lst->head->next;
		lst->head->prev = tmp;
		lst->tail = tmp;
		lst->tail->next = lst->head;
		lst->res++;
//	}
	write(1, "ra\n", 3);
}

void	ft_rb(t_lst *lst)
{
	t_node	*tmp;

//	if (lst->cnt > 1)
//	{
		tmp = lst->head;
		lst->head = lst->head->next;
		lst->head->prev = tmp;
		lst->tail = tmp;
		lst->tail->next = lst->head;
		lst->res++;
//	}
	write(1, "rb\n", 3);
}

void	ft_rra(t_lst *lst)
{
	t_node	*tmp;

	tmp = lst->head;
	lst->head = lst->tail;
	lst->tail = lst->tail->prev;
	lst->head->next = tmp;
	lst->res++;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_lst *lst)
{
	t_node	*tmp;

	tmp = lst->head;
	lst->head = lst->tail;
	lst->tail = lst->tail->prev;
	lst->head->next = tmp;
	lst->res++;
	write(1, "rrb\n", 4);
}

void	ft_del(t_lst *t)
{
	t_node *tmp;

	tmp = t->head;
	t->head = tmp->next;
	t->head->prev = tmp->prev;
	t->tail->next = t->head;
	t->cnt--;
	t->res++;
	//free(tmp);
	tmp = NULL;
}

int	ft_pa(t_lst *a, t_lst *b)
{
	ft_node_init(b, a->head->data);
	ft_del(a);
	write(1, "pa\n", 3);
	return (1);
}

int	ft_pb(t_lst *b, t_lst *a)
{
	ft_node_init(a, b->head->data);
	ft_del(b);
	write(1, "pb\n", 3);
	return (1);
}
