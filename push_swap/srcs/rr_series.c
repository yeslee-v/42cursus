/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_series.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:05:14 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/28 01:16:07 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_lst *lst)
{
	t_node	*tmp;

	tmp = lst->head;
	lst->tail = lst->tail->prev;
	lst->tail->next = lst->head->next;
	lst->head = tmp;
	lst->head->prev = lst->tail->prev;
	printf("%d %d\n", lst->head->data, lst->tail->data); // error
}
