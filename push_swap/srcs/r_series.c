/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_series.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:02:18 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/28 01:04:30 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_lst *lst)
{
	t_node	*tmp;

	tmp = lst->head;
	lst->head = lst->head->next;
	lst->head->prev = tmp;
	lst->tail = tmp;
	lst->tail->next = lst->head;
}

void	ft_rb(t_lst *lst)
{
	t_node	*tmp;

	tmp = lst->head;
	lst->head = lst->head->next;
	lst->head->prev = tmp;
	lst->tail = tmp;
	lst->tail->next = lst->head;
}
