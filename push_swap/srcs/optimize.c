/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:09:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/07 20:29:41 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_lst *lst)
{
	t_node *x;
	t_node *y;
	t_node *z;

	x = lst->head;
	y = lst->head->next;
	z = lst->head->next->next;
	if ((x->data < z->data) && (y->data < z->data))
	{
		if (x->data < y->data)
			write(1, "OK\n", 3);
		else
		{
			ft_sa(lst);
			write(1, "sa\n", 3);
		}
	}
	else if ((x->data < y->data) && (z->data < y->data))
	{
		if (x->data < z->data)
		{
			ft_sa(lst);
			write(1, "sa\n", 3);
			ft_ra(lst);
			write(1, "ra\n", 3);
		}
		else
			ft_rra(lst);
			write(1, "rra\n", 3);
	}
	else
	{
		if (y->data < z->data)
		{
			ft_ra(lst);
			write(1, "ra\n", 3);
		}
		else
		{
			ft_sa(lst);
			write(1, "sa\n", 3);
			ft_rra(lst);
			write(1, "rra\n", 3);
		}
	}
}

void	ft_sort_two(t_lst *lst)
{
	int	tmp;

	if (lst->head->next->data < lst->head->data)
	{
		tmp = lst->head->data;
		lst->head->data = lst->head->next->data;
		lst->head->next->data = tmp;
	}
}
