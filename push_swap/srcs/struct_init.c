/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:14:17 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/28 22:01:54 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
