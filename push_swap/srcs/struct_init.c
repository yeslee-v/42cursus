/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:14:17 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/27 16:41:49 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_get_node(void)
{
	t_node	*new;

	if (!(new = malloc(sizeof(t_node))))
		return (0);
	new->data = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_lst	*ft_init_list(void)
{
	t_lst	*lst;

	if (!(lst = malloc(sizeof(t_lst))))
		return (0);
	lst->head = NULL;
	lst->num = 0;
	return (lst);
}
